/**
******************************************************************************
* @file         PanaLink.h
* @brief        PanaLink SDK API定义文件
* @mainpage     PanaLink SDK API说明文档
* @author       PSDCD
* @version      V0.3.1
* @date         2021/01/25
* @copyright    Panasonic Software Development Center (Dalian) CO.,LTD
******************************************************************************
*/

#ifndef _PANALINK_H
#define _PANALINK_H

#ifdef __cplusplus
extern "C"
{
#endif

/* header file */
#include <stdbool.h>
#include <pthread.h>
#include <signal.h>

/* define SDK return value */
#define PLK_RET_OK      true                                                                                ///<PanaLink SDK API返回值：正常结束
#define PLK_RET_ERR     false                                                                               ///<PanaLink SDK API返回值：内部处理错误
typedef bool PLKStatus;                                                                                     ///<PanaLink SDK API返回值类型

/* max value */
#define MAX_MAC_LENGTH                      (12+1)                                                          ///<MAC地址长度
#define MAX_DEVICE_TYPE_LENGTH              (4)                                                             ///<设备类型最大长度
#define MAX_ROM_ID_LENGTH                   (16)                                                            ///<ROM ID最大长度
#define MAX_DEVICE_ID_LENGTH                (MAX_MAC_LENGTH+MAX_DEVICE_TYPE_LENGTH+MAX_ROM_ID_LENGTH+2)     ///<DEVICE ID 最大长度
#define POST_CONTEXT_LENGTH                 (4096)                                                          ///<上报给服务器信息的最大长度
#define HTTPS_RECV_BUF_LENGTH               (4096)                                                          ///<接收到服务器数据的最大长度
#define DOWNLOAD_BUF_LENGTH                 (4096)
#define URL_SIZE                            (256)
#define FILENAME_SIZE                       (1024)
#define DESCRIPTION_SIZE                    (1024)
#define CLOUDPROGRAMLIST_SIZE               (50)
#define MEDIALIST_SIZE                      (50)
#define STRING_SIZE                         (64)
#define CMDLIST_SIZE                        (50)
#define HSAH_SIZE                           (1024)
#define CER_SIZE                            (2048)
#define TITLE_SIZE                          (1024)
#define INFO_SIZE                           (128)
#define CONTENT_SIZE                        (4096)

/**
******************************************************************************
* @brief
*    信息种类区分   
******************************************************************************
*/
#define ATTRIBUTE_BODY      0x01          ///< 本体属性变化时属性值
#define ATTRIBUTE_OTA       0x02          ///< OTA相关状态变更时属性值
#define ATTRIBUTE_CPM       0x04          ///< 下载云程序时属性值
#define ATTRIBUTE_OTHER     0x08          ///< 其他数据变更时属性值

/***************************************request struct section*************************************/
/**
* @struct 
* @brief 上报信息 (UPDATESTATUSCOMMON 方法指令使用)
*/

typedef struct _toServerSendData{
    unsigned char attrSetting;                 ///< 洗衣机相关属性集合  本体属性变化时属性值:    ATTRIBUTE_BODY  
                                               ///<                     OTA相关状态变更时属性值: ATTRIBUTE_OTA
                                               ///<                     下载云程序时属性值:      ATTRIBUTE_CPM
                                               ///<    例1：如果本体属性变更 attrSetting = ATTRIBUTE_BODY
                                               ///<    例2：如果本体属性和OTA相关状态变更 attrSetting = ATTRIBUTE_BODY | ATTRIBUTE_OTA...
    /*本体->共同属性*/
    unsigned char runingStage;                 ///< 运转阶段                        0:电源待机  1:初期设定  2:运转中  3  4:预约中 5:运转终了  6:异常中 7:途中关机
    unsigned char runingStatus;                ///< 暂停/启动状态                   0:暂停      1:启动
    unsigned char gateStatus;                  ///< 机门状态                        1:门关      0:门开
    unsigned char bodyMode;                    ///< 模式                            0:正常模式  1:非正常模式
    unsigned char memStatus;                   ///< 自编程存储标志                  0:不记忆  1:记忆
    unsigned char bodyOperating;               ///< 本体操作中状态                  1:本体操作中  0:不在本体操作中
    unsigned char bodyHandle;                  ///< 本体处理中                      0:本体不在处理中  1:本体处理中
    unsigned char clothCheck;                  ///< 布量检知状态                    0:无布量检知  1:有布量检知
    unsigned char pushInfo;                    ///< APP控制指令                     0:无          1:APP记录本次洗衣内容并推送洗衣完成    2:APP推送手动关机中
    unsigned char softener;                    ///< 柔软剂                          0--无  1--有
    unsigned char detergent;                   ///< 洗涤剂                          0--无  1--有
    unsigned char agLackRemind;                ///< Ag不足提醒                      0:正常1:不足提醒
    unsigned char softenerLack;                ///< 柔软剂自投入残量状态            0:残量满  1:残量少
    unsigned char detergentLack;               ///< 洗涤剂自投入残量状态            0:残量满1:残量少
    unsigned char program;                     ///<
                                               ///<滚 筒： 0-SMART          1-棉织物       2-化纤          3-羊毛              4-丝绸内衣  
                                               ///<        5-运动服         6-衬衫         7-混合洗        8-羽绒服            9-筒洗净  
                                               ///<        10-夜洗          11-大物        12-浸泡洗       13-超快速15         14.快速  
                                               ///<        15-除菌          16-节能洗      17-能效         18-A+               19-单脱水模式  
                                               ///<        20-棉普通        21-自编程      22-超柔         23-NANOE除菌        28-Nanoe防霉  
                                               ///<        24-户外服        25-牛仔        26-除螨         27-Nanoe除味        29-净漂
                                               ///<        30-亮彩          31-单洗        32-单漂洗       33-单脱水           34-自动烘干   
                                               ///<        35-低温烘干      36-定时烘干    37-单烘干       38-active speed     39-collar and sleeve
                                               ///<        40-oily sauce    41-mud         42-cotton eco   43-ECONAVI_NA       44-自投入保养  
                                               ///<        45-筒保养        46-Daily       47-COTTON_A     48-COTTON_ECO_A     49-NanoeX护衣  
                                               ///<        50-NanoeX防过敏  51-NanoeX除皱  52-NanoeX蓬松   53-NanoeX毛皮养护   ≥ 100厂家发布程序
                                               ///<        100-净漂（云程序）、101-牛仔（云程序）、102-浸泡洗（云程序）、103-亮彩（云程序）、104-超柔（云程序）、105-nanoeX筒防霉（100~149预留为云程序使用）
                                               ///<
                                               ///<波轮：  0-常用、1-节能洗、2-强洗、3-超快速、4-桶洗净、5-羊毛洗、6-丝绸洗、7-羽绒洗、8-大件洗、9-记忆、10-认证程序
                                               ///<
                                               ///<干衣机：0-nanoeX除菌、1-nanoeX除味、2-柔顺、3-焕新、4-nanoeX除过敏、5-nanoeX除皱、6-nanoeX蓬松、7-nanoeX毛皮养护、
                                               ///<        8-棉织物、9-羊毛、10-户外服、11-大物、12-75℃除菌、13-羽绒服、14-5分钟急速护理、15-定时烘干20分、16-定时烘干40分、
                                               ///<        17-定时烘干60分、18-化纤、19-丝绸内衣、20-运动服、21-快烘、22-混合、23-定时暖风、24-定时冷风
                                               ///< 
                                               ///<压 洗： 0-丝绸、1-羊毛
                                               ///<
    unsigned char spinCycleOrg;                ///< 初始-脱水中行程(脱水)           0--无 1--有
    unsigned char rinseCycleOrg;               ///< 初始-漂洗中行程                 0--无 1--有
    unsigned char washCycleOrg;                ///< 初始-洗涤中行程                 0--无 1--有
    unsigned char preWashOrg;                  ///< 初始-预洗（浸泡）中行程         0--无 1--有
    unsigned char spinCycleCur;                ///< 现时点-脱水中行程(脱水)         0--无 1--有
    unsigned char rinseCycleCur;               ///< 现时点-漂洗中行程               0--无 1--有
    unsigned char washCycleCur;                ///< 现时点-洗涤中行程               0--无 1--有
    unsigned char preWashCur;                  ///< 现时点-预洗（浸泡）中行程       0--无 1--有
    unsigned char activeFoam;                  ///< 泡沫净功能                      0--无 1--有
    unsigned char agPlus;                      ///< 光动银功能                      0--无 1--有
    unsigned char mute;                        ///< 静音功能                        0--无 1--有
    unsigned char childLock;                   ///< 儿童锁功能                      0--无 1--有
    unsigned char rinseTime;                   ///< 漂洗                            0-无  1-1回  2-2回  3-3回  4-4回
    unsigned char rinseType;                   ///< 漂洗模式                        0-蓄水漂洗 1-注水漂洗
    unsigned char waterLevel;                  ///< 水位.                 1.滚筒:   0--少量(未使用)1--低 2--中 3--高 5--最高
                                               ///<                       2.波轮:   0x01--32L、0x03--38L、0x04--44L、0x05--52L、0x06--58L、0x07--66L、 0x08--72L、0x09--78L、0x0a--82L、0x0c--85L
    unsigned short washTime;                   ///< 洗涤时间:(单位:分)             (0~1023分钟)
    unsigned char spinTime;                    ///< 脱水时间                        0~127min
    unsigned char timeDelayTotal;              ///< 预约设定值 单位:小时 预约范围: 0(h) -- 24(h）
    unsigned char timeDelayResidual;           ///< 预约剩余时间 = 预约总时间 - 经过时间 单位:小时预约剩余时间范围:0(h) -- 24(h)
    unsigned char abnormalNumber;              ///< 异常编号（例03)
    unsigned char abnormalState;               ///< 异常类型                        0--U异常 1--H异常
    unsigned short demandResidualTime;         ///< 洗衣机总需求的剩余时间 单位:分 范围:000(分) -- 599(分）
    unsigned short currentResidualTime;        ///< 洗衣机现时点的剩余时间 单位:分 范围:000(分) -- 599(分）
    unsigned char washMode;                    ///< 洗衣模式                        0-洗涤模式 1-洗干模式 2-烘干模式 3-护理模式 4-健康模式
    unsigned char programJudgment;             ///< 自定义程序判断                  0-否 1-是
    unsigned char powerVer;                    ///< 电源侧版本                      版本:0--15
    unsigned char displayVer;                  ///< 显示侧版本                      版本:0--15
    unsigned char touchICVer;                  ///< 触摸IC版本                      版本:0--15
    unsigned char clothQuality_wash;           ///< 布量等级(洗涤)                  0--布量等级0 1--布量等级12--布量等级2 …
    unsigned short waterTemp;                  ///< 水温
    unsigned short voltage;                    ///< P电压

    /*本体->共同属性预留数据位*/
    unsigned char reservedByte[16];            ///< reservedByte[0]   第 0 bit位  表示 离心去污有无设定标志  0: 没有设定，1：有设定
                                               ///<                   第 1 bit位  表示 保温状态有无设定标志  0: 没有设定，1：有设定
                                               ///<                   第 2—5 bit位 预留
                                               ///<                   第 7 bit位  表示 洗涤时间有无设定标志  0: 没有设定，1：有设定
                                               ///<                   第 8 bit位  表示 水位有无设定标志      0: 没有设定，1：有设定

    	
   
    /*本体->滚筒独有数据*/
    unsigned char gateLock;                    ///< 门锁状态                        1:上锁      0:解锁
    unsigned char highTempStatus;              ///< 筒高温状态                      0:非高温状态  1:高温状态
    unsigned char supplyAirCycleStatus;        ///< 送风行程状态                    0:无  1:第二空冷中  2:第二空冷终了
    unsigned char forcedAirCooling;            ///< 强制空冷状态                    0:未设定  1:强制空冷中
    unsigned char bitsClog;                    ///< 线屑堵塞状态                    0:未堵塞  1:有堵塞
    unsigned char isSetting;                   ///< 详细设定标志                    1:进入详细设定 0:未进入详细设定
    unsigned char forbidSetting;               ///< 切换禁止状态                    0:切换允许    1:切换禁
    unsigned char remoteControl;               ///< 远程控制状态                    0:OFF  1:ON
    unsigned char remoteControlFunction;       ///< 远程控制功能有无标志位          0--无该功能  1--有该功能
    unsigned char popupStatus;                 ///< 自投入缺失提醒弹框              0:无 1:洗涤剂缺失提醒 2:柔软剂缺失提醒 3:洗涤剂柔软剂缺失提醒
    unsigned char softenerPouredVolume;        ///< 柔软剂投入量                    1--轻污 2--标准 3--重污
    unsigned char detergentPouredVolume;       ///< 洗涤剂投入量                    1--轻污 2--标准 3--重污
    unsigned char coolOrg;                     ///< 初始-冷却中                     0--无 1--有
    unsigned char easyIroningOrg;              ///< 初始-衣物抖散&轻柔送风          0--无 1--有
    unsigned char supplyAirOrg;                ///< 初始-烘干中行程(送风)           0--无 1--有
    unsigned char dryOrg;                      ///< 初始-烘干中行程(烘干)           0--无 1--有
    unsigned char nanoeOrg;                    ///< 初始-Nanoe行程                  0--无 1--有
    unsigned char preHandleOrg;                ///< 初始-预处理行程                 0--无 1--有
    unsigned char coolCur;                     ///< 现时点-冷却中                   0--无 1--有
    unsigned char easyIroningCur;              ///< 现时点-衣物抖散&轻柔送风        0--无 1--有
    unsigned char supplyAirCur;                ///< 现时点-烘干中行程(送风)         0--无 1--有
    unsigned char dryCur;                      ///< 现时点-烘干中行程(烘干)         0--无 1--有
    unsigned char nanoeCur;                    ///< 现时点-Nanoe行程                0--无 1--有
    unsigned char preHandleCur;                ///< 现时点-预处理行程               0--无 1--有
    unsigned char nanoe;                       ///< nanoe预处理功能                 0--无 1--有
    unsigned char preWash;                     ///< 带预洗功能                      0--无 1--有
    unsigned char extraRinse;                  ///< 加漂洗功能                      0--无 1--有
    unsigned char easyIroning;                 ///< 免熨烫功能                      0--无 1--有
    unsigned char spinSpeed;                   ///< 脱水转速 正常转速0~14:          0--500r/min 1--600r/min 2--700r/min … 14--1900r/min(步进100r/min) 特殊转速15:15--无转速
    unsigned char temperature;                 ///< 温度                  1.滚筒：  0--冷水 1--30℃ 2--40℃ 3--50℃ 4--60℃ 6--70℃ 7--80℃ 8--90℃ 9--95℃ 10--100℃
    unsigned char dryType;                     ///< 烘干模式              1.滚筒:   0-自动烘干  1-低温烘干  2-定时烘干    
    unsigned short dryTime;                    ///< 烘干时间设定                    0~500分钟
    unsigned char clothQuality_dry;            ///< 布量等级(烘干)                  0--布量等级0 1--布量等级1 2--布量等级2
    unsigned char timingDryAjust;              ///< 自动烘干/定时烘干:调整时间设定  0-烘干时间显示不调整 1-烘干时间显示+30min
    unsigned char autoDryAjust;                ///< 自动烘干调整时间                0-自动烘干显示无变更 1-自动烘干显示减少20min
    unsigned char wakeupVer;                   ///< 智能唤醒侧版本                  版本:0--15
    unsigned char clothAmount;                 ///< 布质等级                        0--布质等级0 1--布质等级1 2--布质等级2

    
    /*本体->波轮独有数据*/
    unsigned char openAbnormal;                ///< 机盖开异常提醒                  0-无    1-有
    unsigned char spinTimeChange;              ///< 脱水时间变更许可标志            0-随水位改变   1-不随水位改变
    unsigned char econaviRemind;               ///< ECONAVI提醒                     0-无    1-有
    unsigned char barrelCleanFunction;         ///< 桶自洁功能                      0-无    1-有
    unsigned char soakingTime;                 ///< 浸泡时间                        0-168分
    unsigned short agSpinCycle;                ///< 光动银运转回数
    unsigned char washCycleJudgment;           ///< 洗涤行程判断                    0-洗涤行程运行中 1-洗涤行程结束
    unsigned char soakCycleJudgment;           ///< 浸泡行程判断                    0-浸泡行程运行中 1-浸泡行程结束
    
    /*本体->干衣机独有数据*/
    unsigned char addWaterRemind;              ///< nanoe加水提醒                   0-无   1-有
    unsigned char waterFullRemind;             ///< 水盒水满提醒                    0-无   1-有
    unsigned char filterCleanRemind;           ///< 过滤网清洗提醒                  0-无   1-有
    unsigned char endBeepChange;               ///< 终了蜂鸣音有无切换              0-无   1-有
    unsigned char mildDry;                     ///< 温和干燥                        0-无   1-有

    
    /* OTA相关属性 */
    /* OTA相关上报相关case说明
    1）接受到OTA升级指令后
       发送：otaStatus：1（开始升级）       otaResult：0（结果复归为无效）
    2）OTA升级成功后
       发送：otaStatus：0（退出升级状态）   otaResult：1（升级成功）
    3）OTA升级失败后
       发送：otaStatus：0（退出升级状态）   otaResult：2（升级失败）
    */
    unsigned char otaStatus;                   ///< OTA升级状态                     0 未开始 1开始升级
    unsigned char otaResult;                   ///< OTA升级结果                     0 无效 1 升级成功 2 升级失败
    /*云程序相关属性*/
    /* 云程序上报相关case说明
    1）接受到云程序下载指令后
       发送： cpmStatus：1（开始下载）         cpmId：12（云程序ID）  cpmResult：0 无效
    2）下载成功后
       发送： cpmStatus：0（退出下载状态）     cpmId：12（云程序ID）  cpmResult：1（下载成功）
    3）下载失败后
       发送： cpmStatus：0（退出下载状态）     cpmId：12（云程序ID）  cpmResult：2（下载失败）
    4）删除成功后
       发送： cpmStatus：0（退出下载状态）     cpmId：12（云程序ID）  cpmResult：3（删除成功）
    5) 删除失败后无需上报
     */
    unsigned char cpmStatus;                   ///< 云程序下载状态                  0 未下载 1 下载中
    unsigned int  cpmId;                       ///< 云程序ID
    unsigned char cpmResult;                   ///< 云程序下载结果                  0 无效  1下载成功 2 下载失败 3 删除成功 4 删除失败

    /*其他数据*/
    /* 
     * 自定义程序时上报下发(customizeName)，其它程序不处理
     */
    char customizeName[TITLE_SIZE];            ///< 自定义程序名称

    /* 
     * 云程序运行时上报下发(paramTypeId) 其它程序不处理
     */
    int  paramTypeId;                          ///< 云程序分类

}SendData;

/**@struct GetMediaListInfoReq_t
* @brief 获取洗衣之家资讯列表请求结构体 (GETMEDIALIST 方法指令使用)
*/
typedef struct _get_media_list_info{
    int urltypeid;                                                  ///< 资源类型   -1:不参照该参数  0:长图片      1:视频       2:超链接
    int classid;                                                    ///< 类目ID     -1:不参照该参数  0:洗衣方式    1:功能介绍   2:其他类目
    unsigned int page;                                              ///< 页码       从 1 开始  如果 page 值是 0 代表查看全部信息
    unsigned int size;                                              ///< 每页条数
}GetMediaListInfoReq_t;


/**@struct UpdateFwVersionReq_t
* @brief 向CA服务器发送固件版本号（UPDATEFWVERSION 方法指令使用)
*/
typedef struct _update_fw_version{
    char firmware[100];                                             ///< firmware版本
}UpdateFwVersionReq_t;


/**@struct GetCloudProgramListReq_t
* @brief 向CA服务器申请云程序列表信息（(GETCLOUDPROGRAMLIST 方法指令使用)
*/
typedef struct get_cloud_program_list{
    int downloadFlag;                                               ///< 是否已下载 -1:不参照该参数(代表全部) 0:未下载 1:已下载 2:下载中 
    unsigned int page;                                              ///< 页码       从 1 开始  如果 page 值是 0 代表查看全部信息
    unsigned int size;                                              ///< 每页数量
}GetCloudProgramListReq_t;

/**@struct GetCloudProgramInfoReq_t
* @brief 向CA服务器申请cpmId对应的云程序信息（(GETCLOUDPROGRAMINFO 方法指令使用)
*/
typedef struct get_cloud_program_info{
    int cpmId;                                                     ///< 云程序ID
}GetCloudProgramInfoReq_t;


/*************************************** respond struct section *************************************/
 
/**
 *@section　error section
 *  0~4096        0~0x1000            保留code
 *  4097            0x1001            通信报文不符合JSON格式
 *  4098            0x1002            通信Metod不存在
 *  4099            0x1003            必要的属性不存在
 *  4100            0x1004            不是有效的家电
 *  4101            0x1005            params中内容不足
 *  4102~8190    0x1006~0x1FFE        保留code
 *  8191            0x1FFF            服务器内部错误
 *  8193            0x2001            家电内部错误
 *
 *error section end
*/

/**
* @struct
* @brief 下发信息parameters
*/
typedef struct _fromServerReceiveDataInfo{

    unsigned int todoId;                       ///< todoId
    char method[100];                          ///< "Set"

    unsigned char attrSetting;                 ///< 手机APP 下发信息种类标志位
                                               ///< 洗衣机相关属性集合  本体属性变化时属性值:    ATTRIBUTE_BODY  
                                               ///<                     OTA相关状态变更时属性值: ATTRIBUTE_OTA
                                               ///<                     下载云程序时属性值:      ATTRIBUTE_CPM
                                               ///< 例1：如果本体属性变更 attrSetting = ATTRIBUTE_BODY
                                               ///< 例2：如果本体属性和OTA相关状态变更 attrSetting = ATTRIBUTE_BODY | ATTRIBUTE_OTA...
    /* 本体->共同相关属性 */
    unsigned char program;                     ///<
                                               ///<滚 筒： 0-SMART          1-棉织物       2-化纤          3-羊毛              4-丝绸内衣  
                                               ///<        5-运动服         6-衬衫         7-混合洗        8-羽绒服            9-筒洗净  
                                               ///<        10-夜洗          11-大物        12-浸泡洗       13-超快速15         14.快速  
                                               ///<        15-除菌          16-节能洗      17-能效         18-A+               19-单脱水模式  
                                               ///<        20-棉普通        21-自编程      22-超柔         23-NANOE除菌        28-Nanoe防霉  
                                               ///<        24-户外服        25-牛仔        26-除螨         27-Nanoe除味        29-净漂
                                               ///<        30-亮彩          31-单洗        32-单漂洗       33-单脱水           34-自动烘干   
                                               ///<        35-低温烘干      36-定时烘干    37-单烘干       38-active speed     39-collar and sleeve
                                               ///<        40-oily sauce    41-mud         42-cotton eco   43-ECONAVI_NA       44-自投入保养  
                                               ///<        45-筒保养        46-Daily       47-COTTON_A     48-COTTON_ECO_A     49-NanoeX护衣  
                                               ///<        50-NanoeX防过敏  51-NanoeX除皱  52-NanoeX蓬松   53-NanoeX毛皮养护   ≥ 100厂家发布程序
                                               ///<        100-净漂（云程序）、101-牛仔（云程序）、102-浸泡洗（云程序）、103-亮彩（云程序）、104-超柔（云程序）、105-nanoeX筒防霉（100~149预留为云程序使用）
                                               ///<
                                               ///<波轮：  0-常用、1-节能洗、2-强洗、3-超快速、4-桶洗净、5-羊毛洗、6-丝绸洗、7-羽绒洗、8-大件洗、9-记忆、10-认证程序
                                               ///<
                                               ///<干衣机：0-nanoeX除菌、1-nanoeX除味、2-柔顺、3-焕新、4-nanoeX除过敏、5-nanoeX除皱、6-nanoeX蓬松、7-nanoeX毛皮养护、
                                               ///<        8-棉织物、9-羊毛、10-户外服、11-大物、12-75℃除菌、13-羽绒服、14-5分钟急速护理、15-定时烘干20分、16-定时烘干40分、
                                               ///<        17-定时烘干60分、18-化纤、19-丝绸内衣、20-运动服、21-快烘、22-混合、23-定时暖风、24-定时冷风
                                               ///< 
                                               ///<压 洗： 0-丝绸、1-羊毛
                                               ///<
    unsigned char spinCycle;                   ///< 脱水行程                         0--无 1--有
    unsigned char rinseCycle;                  ///< 漂洗行程                         0--无 1--有
    unsigned char washCycle;                   ///< 洗涤行程                         0--无 1--有
    unsigned char preWashCycle;                ///< 预洗(浸泡)行程                   0--无 1--有
    unsigned char softener;                    ///< 自投入有无判定-柔软剂            0--无 1--有
    unsigned char detergent;                   ///< 自投入有无判定-洗涤剂            0--无 1--有
    unsigned char activeFoam;                  ///< 泡沫净功能                       0--无 1--有
    unsigned char agPlus;                      ///< 光动银功能                       0--无 1--有
    unsigned char mute;                        ///< 静音功能                         0--无 1--有
    unsigned char childLock;                   ///< 儿童锁功能                       0--无 1--有
    unsigned char runingStatus;                ///< 暂停/启动状态                    0x00---暂停   0x01---启动
    unsigned char powerStatus;                 ///< 开/关机状态                      0x00---电源关 0x01---电源开
    unsigned char waterLevel;                  ///< 水位                   1.滚筒:   0--少量(未使用) 1--低 2--中 3--高-(未使用) 4--高 5--最高(未使用)
                                               ///<                        2.波轮:   0x01--32L、0x03--38L、0x04--44L、0x05--52L、0x06--58L、0x07--66L、 0x08--72L、0x09--78L、0x0a--82L、0x0c--85L
    unsigned char rinseTime;                   ///< 漂洗回数设定                     0-无 1-1回 2-2回 3-3回 4-4回
    unsigned char rinseType;                   ///< 漂洗模式                         0-蓄水漂洗1-注水漂洗
    unsigned short washTime;                   ///< 洗涤时间设定                     0~1023分钟
    unsigned char spinTime;                    ///< 脱水时间                         0~127min
    unsigned char timeDelayTotal;              ///< 预约时间                         0(h)--24(h）0x00--0x18
    unsigned char washMode;                    ///< 洗衣模式                         0-洗涤模式 1-洗干模式 2-烘干模式 3-护理模式 4-健康模式
    unsigned char programJudgment;             ///< 自定义程序判断                   0-否 1-是
    unsigned char waterLevelSwitch;            ///< 水位有无设定标志                 0-无  1-有设定
    
    /*本体->滚筒独有数据*/
    unsigned char coolCycle;                   ///< 冷却工程行程                     0--无 1--有
    unsigned char easyIroningCycle;            ///< 免熨烫行程                       0--无 1--有
    unsigned char supplyAirCycle;              ///< 送风行程                         0--无 1--有
    unsigned char dryCycle;                    ///< 干燥行程                         0--无 1--有
    unsigned char nanoeCycle;                  ///< nanoe行程                        0--无 1--有
    unsigned char preHandleCycle;              ///< 预处理行程                       0--无 1--有
    unsigned char popupStatus;                 ///< 自投入缺失提醒弹框               0--无 1-洗涤剂缺失提醒 2-柔软剂缺失提醒
    unsigned char softenerPouredVolume;        ///< 自动投入量-柔软剂投入量          1--轻污 2--标准 3--重污（1  2  3代表有）
    unsigned char detergentPouredVolume;       ///< 自动投入量-洗涤剂投入量          1--轻污 2--标准 3--重污（1  2  3代表有）
    unsigned char nanoe;                       ///< nanoe预处理功能                  0--无 1--有
    unsigned char preWash;                     ///< 带预洗                           0--无 1--有
    unsigned char extraRinse;                  ///< 加漂洗                           0--无 1--有
    unsigned char easyIroning;                 ///< 免熨烫                           0--无 1--有
    unsigned char spinSpeed;                   ///< 脱水转速 正常转速0~14:           0--500r/min 1--600r/min 2--700r/min … 14--1900r/min(步进100r/min) 特殊转速15:15--无转速
    unsigned char temperature;                 ///< 温度                   1.滚筒:   0--冷水 1--30℃ 2--40℃ 3--50℃ 4--60℃ 6--70℃ 7--80℃ 8--90℃ 9--95℃ 10--100℃
    unsigned char dryType;                     ///< 烘干模式               1.滚筒:   0-自动烘干  1-低温烘干  2-定时烘 
    unsigned short dryTime;                    ///< 烘干时间设定                     0~500分
    unsigned char runTimeSwitch;               ///< 运转时间有无设定标志             0-无  1-有设定
    unsigned char isSetting;                   ///< 详细设定标志                     1:进入详细设定 0:未进入详细设定

    /*本体->波轮独有数据*/
    unsigned char barrelCleanFunction;         ///< 桶自洁功能                      0-无    1-有
    unsigned char soakingTime;                 ///< 浸泡时间                        范围:0(分)、30(分)、40(分)、50(分)、60(分)、70(分) 、80(分) 、168(分)

    /*本体->干衣机独有数据*/
    unsigned char endBeepChange;               ///< 终了蜂鸣音有无切换              0--无1--有
    unsigned char mildDry;                     ///< 温和干燥                        0--无1--有

    /*本体->共同属性预留数据位*/
    unsigned char reservedByte[4];               ///< reservedByte[0]  第0、1bit位 表示 二维码绑定结果  0: 没有做扫码绑定操作，1：表示扫码绑定成功  2：表示扫码绑定失败
                                                 ///<                  第   2bit位 表示 app地域信息变更 0: 没有变更   1: 有变更
                                                 ///< reservedByte[1]  第0 bit位   表示 离心去污有无设定标志  0: 没有设定，1：有设定

    /* OTA相关属性 */
    unsigned char otaStatus;                   ///< OTA升级状态                      0 未开始 1开始升级
    /* 云程序相关属性 */
    unsigned char cpmStatus;                   ///< 云程序下载状态                   0 未下载 1开始下载 2 删除云程序
    unsigned int  cpmId;                       ///< 云程序ID
    
    /*其他数据*/
    /* 
     * 自定义程序时上报下发(customizeName)，其它程序不处理
     */
    char customizeName[TITLE_SIZE];            ///< 自定义程序名称

    /* 
     * 云程序运行时上报下发(paramTypeId) 其它程序不处理
     */
    int  paramTypeId;                          ///< 云程序分类

}ReceiveDataInfo;

/**
* @struct
* @brief 下发信息对应的应答结构体 (HEARTBEAT 方法指令使用)
*/
typedef struct _fromServerReceiveData{
    int  resultcode;                           ///<应答结果        8194:success  小于8194：对应的error code 参照【error section】8195:应答中没有error code时对应的失败
    bool serverRemote;                         ///<服务器有无远程操作 true:有远程操作，false:没有远程操作
    int  listNum;                              ///<服务器操作指令List数据的条数
    ReceiveDataInfo dataInfo[CMDLIST_SIZE];    ///<远程操作参数设定
}ReceiveData;

/**@struct CommonAck_t
* @brief 应答结构体  
* (UPDATESTATUSCOMMON、DELETEALLAPPCONNECT、UPDATEFWVERSION 方法指令使用)
*/
typedef struct _common_ack{
    int resultcode;                            ///<应答结果        8194:success  小于8194：对应的error code 参照【error section】8195:应答中没有error code时对应的失败
}CommonAck_t;

/**@struct GetSharingQRCodeAck_t
* @brief 获取二维码用于绑定app对应的应答结构体 (GETSHARINGQRCODE 方法指令使用)
*/
typedef struct _get_sharing_qrcode_ack{
    int  resultcode;                           ///<应答结果        8194:success  小于8194：对应的error code 参照【error section】8195:应答中没有error code时对应的失败
    char qrCode[13];                           ///<服务器为该设备ID生成的临时随机字符串,长度暂定：12位,可以包含字母和数字
}GetSharingQRCodeAck_t;

/**@struct GetCloudProgramInfoAck_t
* @brief 云程序信息对应的应答结构体
*/
typedef struct _get_cloud_program_info_ack{
    int  resultcode;                            ///<应答结果        8194:success  小于8194：对应的error code 参照【error section】8195:应答中没有error code时对应的失败
    int  cpmId;                                 ///<云程序编码
    char ver[STRING_SIZE];                      ///<家电对应的云程序的版本信息 如：“1.0.1”
    char name[STRING_SIZE];                     ///<云程序名称
    char mode[STRING_SIZE];                     ///<云程序类型     0洗涤 1洗干 2烘干 3护理 4健康  如:mode 值是"0,1" 0,1代表即属于洗涤又属于洗干
    char videoUrl[URL_SIZE];                    ///<云程序视频介绍URL
    char imgUrl[URL_SIZE];                      ///<云程序背景图片URL
    char shortDescription[DESCRIPTION_SIZE];    ///<短描述信息 如:大约25分钟 单位（分钟）
    char description[DESCRIPTION_SIZE];         ///<云程序简介信息
    char iconUrl[URL_SIZE];                     ///<云程序图标URL
    //char cerInfo[CER_SIZE];                   ///<证书信息
}GetCloudProgramInfoAck_t;   

/**@struct CloudProgramInfo_t
* @brief 云程序结构体                 (GETCLOUDPROGRAMINFO 方法指令使用)
*/
typedef struct _cloud_program_info{
    GetCloudProgramInfoAck_t cpmInfo;           ///<云程序信息
    int downloadFlag;                           ///<是否已下载    0:未下载 1:已下载 2:下载中
}CloudProgramInfo_t;

/**@struct GetCloudProgramListAck_t
* @brief 云程序List对应的应答结构体   (GETCLOUDPROGRAMLIST 方法指令使用)
*/
typedef struct _get_cloud_program_list_ack{
    int  resultcode;                            ///<应答结果        8194:success  小于8194：对应的error code 参照【error section】8195:应答中没有error code时对应的失败
    int  listNum;                               ///<返回的实际条数  
    CloudProgramInfo_t cpmlistInfo[CLOUDPROGRAMLIST_SIZE];
}GetCloudProgramListAck_t;

/**@struct GetWashDesbordInfoAck_t
* @brief 获取洗衣机的仪表盘信息 对应的应答结构体 (GETWASHDESBORDINFO 方法指令使用)
*/
typedef struct _get_wash_desbord_info_ack{
    int  resultcode;                            ///<应答结果        8194:success  小于8194：对应的error code 参照【error section】8195:应答中没有error code时对应的失败
    char province[STRING_SIZE];                 ///<省
    char city[STRING_SIZE];                     ///<市
    char area[STRING_SIZE];                     ///<区
    char weather[STRING_SIZE];                  ///<天气
    int  temp;                                  ///<温度
    int  humidity;                              ///<湿度
    char suggest[DESCRIPTION_SIZE];             ///<洗衣建议
    char date[STRING_SIZE];                     ///<日期
}GetWashDesbordInfoAck_t;

/**@struct RecordsInfo
* @brief 被记录的media数据
*/
typedef struct _records_Info{
    char coverurl[URL_SIZE];                    ///< 封面图片URL
    char newsno[INFO_SIZE];                     ///< 发布编号
    char model[INFO_SIZE];                      ///< 型号
    char title[TITLE_SIZE];                     ///< 类目
    int  titleid;                               ///< 类目ID
    char url[URL_SIZE];                         ///< 内容url
    char fileName[FILENAME_SIZE];               ///< 文件名称
    char urltype[INFO_SIZE];                    ///< 资源类型
    int  urltypeid;                             ///< 资源类型ID  0 图片        1 视频      2 超链接
    int  classid;                               ///< 类目ID      0 洗衣机方式  1 功能介绍  2其它
    char classidName[INFO_SIZE];                ///< 类目名称
}RecordsInfo;

/**@struct GetMediaListInfoAck_t
* @brief 洗衣之家资讯列表 对应的应答结构体 (GETMEDIALIST 方法指令使用)
*/
typedef struct _get_media_list_info_ack{
    int resultcode;                             ///< 应答结果        8194:success  小于8194：对应的error code 参照【error section】8195:应答中没有error code时对应的失败
    char errorInfo[INFO_SIZE];                  ///< ""
    char status[INFO_SIZE];                     ///< "1"
    int classidSave;                            ///< 申请资源时classid保存
    int listNum;                                ///< 返回的实际条数
    RecordsInfo recordsInfo[MEDIALIST_SIZE];    ///< 被记录的media数据
}GetMediaListInfoAck_t;

/**@struct DeviceResetAck_t
* @brief 恢复出厂设置 对应的应答结构体 (DEVICERESET 方法指令使用)
*/
typedef struct _device_reset_ack{
    int resultcode;                             ///< 应答结果        8194:success  小于8194：对应的error code 参照【error section】8195:应答中没有error code时对应的失败
    char results[INFO_SIZE];                    ///< 结果            "success" 或者 "error"
}DeviceResetAck_t;

/**@struct GetOtaInfoAck_t
* @brief 屏幕升级信息 对应的应答结构体 (GETOTAINFO 方法指令使用)
*/
typedef struct _get_ota_info{
    int  resultcode;                            ///< 应答结果        8194:success  小于8194：对应的error code 参照【error section】8195:应答中没有error code时对应的失败
    char ver[STRING_SIZE];                      ///< 当前最新升级文件版本号
    char hash[HSAH_SIZE];                       ///< 用于屏侧升级的hash值
    char mandatoryUpdate[STRING_SIZE];          ///< 是否为强制更新  “A5”是 /“74”否
}GetOtaInfoAck_t;


/**@union AckUnion_t
* @brief 应答共用体定义
*/
typedef union _ack_union{
    CommonAck_t                   commonAck;
    GetSharingQRCodeAck_t         getSharingQrCodeAck;
    GetCloudProgramInfoAck_t      getCloudProgramInfoAck;
    GetCloudProgramListAck_t      getCloudProgramListAck;
    GetWashDesbordInfoAck_t       getWashDesbordInfoAck;
    GetOtaInfoAck_t               getOtaInfoAck;
    ReceiveData                   receiveData;
    GetMediaListInfoAck_t         mediaListInfoAck;
    DeviceResetAck_t              deviceResetAck;
    CloudProgramInfo_t            cloudProgramInfo;
}AckUnion_t;



/*************************************** other section *************************************/
/**@enum MethodEnum
* @brief 定义枚举值与之对应的功能指令说明
*/
typedef enum _method_enum{
    DELETEALLAPPCONNECT = 0x00,              ///< 发送把全部手机App绑定指令  
    UPDATEFWVERSION,                         ///< 发送本体固件版本信息
    UPDATESTATUSCOMMON,                      ///< 启动时/连接网络时,发送当前全部的设计值以及状态信息
    GETSHARINGQRCODE,                        ///< 获取二维码,用于绑定app
    GETCLOUDPROGRAMLIST,                     ///< 获取云程序列表
    GETWASHDESBORDINFO,                      ///< 获取洗衣机的仪表盘信息
    GETMEDIALIST,                            ///< 获取洗衣之家资讯列表
    DEVICERESET,                             ///< 恢复出厂设置
    HEARTBEAT,                               ///< 下发信息
    GETOTAINFO,                              ///< 获取屏幕升级信息
    GETCLOUDPROGRAMINFO,                     ///< 根据cpmId获取相关云程序信息
    MAXMETHOD,
}MethodEnum;


/**@union DownloadTypeEnum
* @brief 下载类型
*/
typedef enum _download_type{
    DOWNLOAD_OTA,                            ///<  屏侧升级下载
    DOWNLOAD_CLOUD_PROGRAM,                  ///<  云程序下载
    DOWNLOAD_MAX_TYPE,
}DownloadTypeEnum;

/**@union DownloadParams_t
* @brief 下载类型和ID结构体
*/
typedef struct _download_params{
    int cpmId;
    DownloadTypeEnum downloadType;
}DownloadParams_t;

/*CALLBACK Function*/
typedef void (*PanaLinkTodoListNotify)(AckUnion_t toDo, MethodEnum method, unsigned int methodId);                                                              ///<PanaLink SDK提供的回调函数类型：获取到服务器下发内容时，SDK调用此函数
typedef void (*PanaLinkServerConnectCheck)(int Status);                                                                                                         ///<PanaLink SDK提供的回调函数类型：服务器的连接状态变化时，SDK调用此函数  参数 Status 1:连接服务器 -1:未连接服务器 -2:连接服务器错误
typedef void (*PanaLinKDownLoadBuf)(char* buf, int Status, int sizeofbuf, long totalSize, DownloadParams_t* downpoadParams, unsigned int methodId);             ///<PanaLink SDK提供的回调函数类型：在文件下载过程中，SDK调用此函数传送数据 参数 Status 0: 下载完成 1：下载中 2：下载失败
typedef void (*PanaLinkGetMessage)(AckUnion_t Message, unsigned int methodId, int status, MethodEnum method);                                                   ///<PanaLink SDK提供的回调函数类型：从服务器取得需要信息时调用此函数

/**@struct GetReqParamsReq_t
* @brief 向CA服务器发送get请求(SDK内部使用)
*/
typedef struct _get_req_params{
    PanaLinkGetMessage        callback;                                   ///< get请求的callback
    GetMediaListInfoReq_t     mediaListInfo;
    GetCloudProgramListReq_t  cpmListInfo;
    GetCloudProgramInfoReq_t  cpmInfo;
}GetReqParamsReq_t;

/**@union ReqUnion_t
* @brief 应答共用体定义
*/
typedef union _req_union{
    SendData                         sendData;
    GetMediaListInfoReq_t            getMediaListInfoReq;
    UpdateFwVersionReq_t             updateFirmwareReq;
    GetReqParamsReq_t                getReqParamsReq;
    GetCloudProgramListReq_t         getCloudProgramListReq;
    GetCloudProgramInfoReq_t         getCpmInfoReq;
}ReqUnion_t;

/**
******************************************************************************
* @brief
    初始化PanaLink SDK, 注册CALLBACK函数
* @param[in]   CALLBACKFUNC     获取服务器下发内容的回调函数
* @param[in]   CALLBACKFUNC_2   获取服务器的连接状态回调函数
* @return      PLKStatus
* @retval      PLK_RET_OK       正常结束
* @retval      PLK_RET_ERR      内部处理错误
* @attention   确保在调用其他接口函数之前调用本函数进行初始化
******************************************************************************
*/
PLKStatus PanaLinkInit(PanaLinkTodoListNotify CALLBACKFUNC, PanaLinkServerConnectCheck CALLBACKFUNC_2);

/**
******************************************************************************
* @brief
    连接服务器
* @return      PLKStatus
* @retval      PLK_RET_OK       正常结束
* @retval      PLK_RET_ERR      内部处理错误
******************************************************************************
*/
PLKStatus PanaLinkStart();

/**
******************************************************************************
* @brief
    上报信息给服务器
* @param[in]   method           URL中方法
* @param[in]   Message          设置的信息
* @param[in]   methodId         向CA服务器发送请求的唯一标识，与注册的callback函数中的methodId参数一致
                                (如果同一功能指令调用多次，methodId便于区分是哪一次功能指令的应答)
* @param[out]  errInfo          返回的错误信息
* @return      PLKStatus
* @retval      PLK_RET_OK       正常结束
* @retval      PLK_RET_ERR      内部处理错误/或通信错误
* @attention   参数Message必须是符合json格式的字符串
******************************************************************************
*/
PLKStatus PanaLinkSetMessageToServer(MethodEnum method , ReqUnion_t* Message, char *errInfo, unsigned int methodId);

/**
******************************************************************************
* @brief
    从服务器取得信息
* @param[in]   method           URL中方法
* @param[in]   CALLBACKFUNC     获得信息的callback函数
* @param[in]   methodId         向CA服务器发送请求的唯一标识，与注册的callback函数中的methodId参数一致
                                (如果同一功能指令调用多次，methodId便于区分是哪一次功能指令的应答)
* @param[out]  errInfo          返回的错误信息
* @return      PLKStatus
* @retval      PLK_RET_OK       正常结束
* @retval      PLK_RET_ERR      内部处理错误/或通信错误
******************************************************************************
*/
PLKStatus PanaLinkGetMessageFromServer(MethodEnum method, PanaLinkGetMessage CALLBACKFUNC, char *errInfo, unsigned int methodId, ReqUnion_t* req);

/**
******************************************************************************
* @brief
    连接下载文件服务器，下载文件
* @param[in]   downloadParams   下载文件类型/id
* @param[in]   CALLBACKFUNC     接收下载文件内容的回调函数
* @param[in]   methodId         向CA服务器发送请求的唯一标识，与注册的callback函数中的methodId参数一致
                                (如果同一功能指令调用多次，methodId便于区分是哪一次功能指令的应答)
* @return      PLKStatus
* @retval      PLK_RET_OK       正常结束
* @retval      PLK_RET_ERR      内部处理错误/或通信错误
******************************************************************************
*/
PLKStatus PanaLink_DocumentFlow_DownloadTask(DownloadParams_t* downloadParams, PanaLinKDownLoadBuf CALLBACKFUNC, unsigned int methodId);

/**
******************************************************************************
* @brief
    断开服务器通信，释放资源
* @return      PLKStatus
* @retval      PLK_RET_OK       正常结束
* @retval      PLK_RET_ERR      内部处理错误
******************************************************************************
*/
PLKStatus PanaLinkStop();

/**
******************************************************************************
* @brief
    停止下载
* @param[in]   downloadParams   下载文件类型/id
* @return      PLKStatus
* @retval      PLK_RET_OK       正常结束
* @retval      PLK_RET_ERR      内部处理错误/或通信错误
******************************************************************************
*/
PLKStatus PanaLink_DocumentFlow_StopDownload(DownloadParams_t* downloadParams);

#ifdef __cplusplus
}
#endif

#endif /* _PANALINK_H */

