//
// VPAccurateSleepModel.h
// WYPHealthyThird
//
// Created by Zhang Chong on 2018/10/11.
// Copyright © 2018 zc.All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface VPAccurateSleepModel: NSObject

//Type of sleep, upload A7 command sleep flag (type of sleep, upload A7 command sleep flag)
@property (nonatomic, strong) NSString *sleepType;
//Sleep time
@property (nonatomic, strong) NSString *sleepTime;
//Wake up time
@property (nonatomic, strong) NSString *wakeTime;
//Sleep sign
@property (nonatomic, strong) NSString *sleepTag;
//get up score
@property (nonatomic, strong) NSString *getUpScore;
//Deep sleep score Deep sleep score
@property (nonatomic, strong) NSString *deepScore;
//Sleep efficiency score, efficiency score from night to deep sleep
@property (nonatomic, strong) NSString *sleepEfficiencyScore;
//Sleeping efficiency score, from the start of sleep to the first time into the deep sleep
@property (nonatomic, strong) NSString *fallAsleepScore;

//Sleep time score
@property (nonatomic, strong) NSString *sleepTimeScore;
//Exit sleep mode
@property (nonatomic, strong) NSString *exitSleepMode;
//Sleep quality 0 to 4, representing 1 to 5 stars in turn
@property (nonatomic, strong) NSString *sleepQuality;
//Number of nights
@property (nonatomic, strong) NSString *getUpTimes;
//Deep sleep mode
@property (nonatomic, strong) NSString *deepAndLightMode;
//Total sleep duration, in minutes
@property (nonatomic, strong) NSString *sleepDuration;
//Deep sleep time, in minutes
@property (nonatomic, strong) NSString *deepDuration;
//Shallow sleep time, in minutes
@property (nonatomic, strong) NSString *lightDuration;
//Wake up time, in minutes, wake up time
@property (nonatomic, strong) NSString *getUpDuration;
//Other sleep time, in minutes, REM period
@property (nonatomic, strong) NSString *otherDuration;
//The first time you enter deep sleep time, falling asleep efficiency
@property (nonatomic, strong) NSString *firstDeepDuration;
//Average of time from wake to deep sleep, sleep efficiency
@property (nonatomic, strong) NSString *getUpToDeepAve;
//The time represented by a point on the curve, in seconds, it is now 60s
@property (nonatomic, strong) NSString *onePointDuration;
//Accurate sleep type, 1 is precise sleep, 0 is normal sleep
@property (nonatomic, strong) NSString *accurateType;
//Insomnia sign
@property (nonatomic, strong) NSString *insomniaTag;
//Insomnia score
@property (nonatomic, strong) NSString *insomniaScore;
//Number of insomnia
@property (nonatomic, strong) NSString *insomniaTimes;
//beginTime start time, how many minutes to fall asleep specifically, endTime end time, how many minutes to fall asleep specifically
@property (nonatomic, strong) NSArray *insomniaRecord;
//Sleep curve, a hexadecimal string. When the client is parsed, it is converted into a data stream. Every two bytes represents a point, with the high bit in the front and the low bit in the back. The high 3 bits represent the sleep state Deep sleep (0), light sleep (1), rapid eye movement (2), insomnia (3), awakening (4) such as 0x1000, take the high three digits 0x1000>>13, and the value obtained is between 0 and 5. Which of them.
@property (nonatomic, strong) NSString *sleepLine;

//The length of insomnia converted according to the curve
@property (nonatomic, strong) NSString *insomniaDuration;

//For these two fields, if lastType == 1, it means that it needs to be spliced ​​with the previous stage of sleep, if nextType==1, it means that it needs to be spliced ​​with the next stage of sleep. After splicing, in addition to falling asleep and getting up, it needs to be modified, the curve needs to be spliced, and others Use the last paragraph
@property (nonatomic, strong) NSString *lastType;
@property (nonatomic, strong) NSString *nextType;
@property (nonatomic, strong) NSString *mac;

//Create a model based on the read data, if it returns nil, it means that the data analysis failed
+ (instancetype)modelWithAccurateSleepData:(NSData *)accurateSleepData dayNumber:(NSInteger)dayNumber sleepType:(NSInteger)sleepType;

-(int)getUpSleepPercent;
-(int)insomniaPercent;
-(int)eyeMovementPercent;
-(int)lightSleepPercent;
-(int)deepSleepPercent;


@end

NS_ASSUME_NONNULL_END
