#include "AnimateManager.h"

#include "json/rapidjson.h"
#include "json/document.h"

//#include "EffectManager.h"

struct AnimateData {
	//string name;
	double delay;
	int framecount;
	int repeat;
	struct Framedata {
		std::string name;
		Vec2 offset;
		Framedata(void) :name(""), offset(0,0){}
	};
	std::vector<Framedata> framedata;
	AnimateData(void) :/*name(""),*/ delay(0), framecount(0), repeat(1){}
};

AnimateManager* AnimateManager::p_myinstance = nullptr;

AnimateManager* AnimateManager::getInstance()
{
	if (p_myinstance == nullptr)
	{
		p_myinstance = new AnimateManager();
	}
	return p_myinstance;
}

AnimateManager::AnimateManager()
{
}

AnimateManager::~AnimateManager()
{
}

Animation* AnimateManager::createAnimation(const Name& animateName)
{
	CCASSERT(animateData.find(animateName) != animateData.end(), "Animate NOT found");

	SpriteFrame* frame = nullptr;
	Vector<SpriteFrame*> frameVec;
	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();
	const AnimateData& data = animateData[animateName];

	for (int i = 0; i < data.framecount; ++i)
	{
		frame = frameCache->getSpriteFrameByName(data.framedata[i].name);
		CCASSERT(frame != nullptr, "SpriteFrame NOT found");

		//根据缩放比例调整偏移
		float scale = Director::getInstance()->getContentScaleFactor();
		Vec2 vec = (frame->getOffsetInPixels() + data.framedata[i].offset)/scale;
		frame->setOffset(vec);
		frameVec.pushBack(frame);
	}
	return Animation::createWithSpriteFrames(frameVec, data.delay, data.repeat);
}

void AnimateManager::LoadResource(const vector<Name>& resNameList)
{
	std::map<string,AnimateData> animatedata;

	//1.打开文件
	FileUtils* fin = FileUtils::getInstance();
	Data data = fin->getDataFromFile("data/Animate.json");
	CCASSERT(!data.isNull(), "[Animate.json] Lost!");

	//2.载入json
	string str = string((char*)data.getBytes(), data.getSize());
	rapidjson::Document root;
	root.Parse<0>(str.c_str());
	CCASSERT(root.IsObject() && root.HasMember("animatedata"), "illegal [Animate.json]");

	//3.读取json数据
	for (int i = 0; i < (int)root["animatedata"].Size(); i++) {
		string name = root["animatedata"][i]["name"].GetString();
		//animatedata[i].name = root["animatedata"][i]["name"].GetString();
		animatedata[name].delay = root["animatedata"][i]["delay"].GetDouble();
		animatedata[name].framecount = root["animatedata"][i]["framecount"].GetInt();
		animatedata[name].repeat = root["animatedata"][i]["repeat"].GetInt();

		int size = root["animatedata"][i]["framedata"].Size();
		CCASSERT(animatedata[name].framecount != 0 && size != 0, "framecount must NOT equal 0");
		animatedata[name].framedata.resize(size);
		for (int j = 0; j<size; j++) {
			animatedata[name].framedata[j].name = root["animatedata"][i]["framedata"][j]["name"].GetString();
			animatedata[name].framedata[j].offset.x = root["animatedata"][i]["framedata"][j]["x"].GetDouble();

			//此处翻转Y轴（cocos的原点在左下角，偏移是相对图片左上角的）
			animatedata[name].framedata[j].offset.y = - root["animatedata"][i]["framedata"][j]["y"].GetDouble();
		}
	}
	
	//4.载入需要的animateData
	AnimationCache* animationCache = AnimationCache::getInstance();
	for (string name : resNameList)
	{
		CCASSERT(animatedata.find(name) != animatedata.end(), string(name + "animateData NOT exists").c_str());
		this->animateData[name] = animatedata[name];
		if (animatedata[name].delay > 0 && animatedata[name].framecount > 1)
			animationCache->addAnimation(createAnimation(name), name);
	}
}

void AnimateManager::FreeAllResource()
{
	animateData.clear();
	AnimationCache::getInstance()->destroyInstance();
}

void AnimateManager::FreeResource(const vector<Name>& resName)
{
	AnimationCache* animationCache = AnimationCache::getInstance();

	for (auto name : resName)
	{
		animateData.erase(name);
		animationCache->removeAnimation(name);
	}
}

void AnimateManager::playAnimate(const Name& animateName, Sprite* sprite, float playtime, CallFunc* callFunc)
{
	CCASSERT(sprite != nullptr, "[AnimateManager::createAnimate]: Sprite is null");
	CCASSERT(animateData.find(animateName) != animateData.end(), "[AnimateManager::createAnimate] Animate NOT found");
	
	if (animateData[animateName].framecount > 1)
	{
		//播放一段时间的动画
		Animation* animation = AnimationCache::getInstance()->getAnimation(animateName);
		ActionInterval* action = Animate::create(animation);
		if (callFunc != nullptr)
		{
			if (playtime > 0)
			{
				ActionInterval* action2 = Sequence::create(DelayTime::create(playtime), callFunc, NULL);
				action = Spawn::createWithTwoActions(action, action2);
			}
			else
				action = Sequence::create(action, DelayTime::create(.01f), callFunc, NULL);
		}
		sprite->runAction(action);
	}
	else
	{
		//单帧动画
		auto& data = animateData[animateName];
		auto s = SpriteFrameCache::getInstance()->getSpriteFrameByName(data.framedata[0].name)->clone();
		s->setOffset(data.framedata[0].offset / Director::getInstance()->getContentScaleFactor());
		sprite->setSpriteFrame(s);
		if (playtime > 0 && callFunc != nullptr)
			sprite->runAction(Sequence::create(DelayTime::create(playtime), callFunc, NULL));
	}
}


