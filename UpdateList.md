##v0.000
- 建立源代码管理，把项目加入SVN管理

##v0.006
- 大改GameObject
- 新建BulletFactory

##v0.008
- 增加BulletMissile

##v0.009
- 增加怪物血条

##v0.010
- 开始使用SpriteFrameCache
- 增加怪物行走动画

##v0.011
- 开始搭建技能BUFF系统
- 增加CEffect类及其子类

##v0.013
- 添加子弹管理
- 修改子弹创建方式

##v0.014
- 1.完成EffectEnumArea
- 2.GameObject不再继承Layer
- 3.GameObject的update方法和Effect的update由GameObjectLayer统一调用

##v0.016
- 1.完成简易VisualEffect

##v0.017
- 1.去除对cocos2d文件夹的版本控制

##v0.018
- 0.VisualEffect改名为AnimateManager
- 1.初步完成贴图管理模块（TextureManeger)
- 2.初步完成动画管理模块（AnimateManager)
- 3.部分完成技能模块(CSkill)

##v0.019
- 1.从 GameObjectLayer 中分离出 GameObjectManager
- 2.合并 GameObjectLayer 和 GameObjectTouchLayer 并删除GameObjectTouchLayer
- 3.独立波数管理 WaveHelper
- 4.新增技能管理 SkillManager

##v0.020
- 1.为AnimateManager添加json读取功能，今后将从json中读取帧偏移数据

##v0.021
- 1.分离GameObject和sprite
- 2.完成Actor类，专门操作sprite
- 3.新建ActorManeger类，负责管理Actor
- 4.删除Bullet的子类Ball和Missile，子类功能全部合并到Bullet
- 5.增加Actor.json保存Actor相关数据

##v0.022
- 1.将存GameObject指针的类全部改为存ID，以避免野指针的出现

##v0.023
- 1.完成 Actor 的 playEffect() 功能

##v0.024
- 1.重新调整文件位置
- 2.GameObject，GameObjectManager 更名为 Unit, UnitManager 
- 3.完成 CSkillAttactk 类
- 4.完成 CWeapon 类
- 5.重写了 Ability 类

##v0.025
- 1.调整文件位置
- 2.增加层 GameMapLayer、TowerSelectLayer
- 3.增加TowerPos类
- 4.改变地图格式，改用Tiled地图

##v0.026
- 1.基本完成TowerPos类
- 2.完全使用Tiled地图，抛弃原有自定义地图格式，在Tiled地图中实现波数设置
- 3.新建 UpgradeTower类
- 4.完善 TowerSelectLayer 中按钮的交互

##v0.027
- 1.新建 WeaponManager 类负责管理 Cweapon,weapon载入json化
- 2.新建接口父类 ResourceLoader 为需要从文件载入数据的Manager提供统一的接口

##v0.028
- 1.TowerPos 改名为 GridPos
- 2.Upgrade相关名称统一更名为Spell
- 3.完成TowerSelectLayer类的功能，顺序化点击事件的分发，并相应对应的点击事件

##v0.029
- 1.添加 Moddification、Cost类
- 2.完成 Behavior 的相关类（Manager及其子类）
- 3.修改 AnimateManager 的接口，对单帧动画做了优化
- 4.修改 CSkillAttactk 增加锁定目标功能
- 5.完成 SpellTower 的相关操作(建设和升级属性)

##v0.030
- 1.重写 Ability模板类，并添加AbilityValueEx和AbilityKey模板
- 2.修复 CEffectSet 和 CEffectEnumArea 中的bug
- 3.添加UI元素 8座塔和8个升级
- 4.添加8个测试武器

##v0.031
- 1.修改Android.mk， 使之能编译到安卓平台上
- 2.修改Ability提示代码健壮性














