#ifndef _ENCODER_H_
#define _ENCODER_H_

#include "stm32f1xx.h"
#include "tim.h"
//#include "pid.h"
#include "adc.h"
#include <stdio.h>

//电机1的编码器输入引脚
#define MOTO1_ENCODER1_PORT GPIOA
#define MOTO1_ENCODER1_PIN  GPIO_PIN_6
#define MOTO1_ENCODER2_PORT GPIOA
#define MOTO1_ENCODER2_PIN  GPIO_PIN_7

//电机2的编码器输入引脚
#define MOTO2_ENCODER1_PORT GPIOB
#define MOTO2_ENCODER1_PIN  GPIO_PIN_6
#define MOTO2_ENCODER2_PORT GPIOB
#define MOTO2_ENCODER2_PIN  GPIO_PIN_7

//定时器号
#define ENCODER_TIM_1 htim2
#define ENCODER_TIM_2 htim4
#define PWM_TIM     htim3
#define GAP_TIM     htim1

#define MOTOR_SPEED_RERATIO 20u    //电机减速比
#define PULSE_PRE_ROUND 13 //一圈多少个脉冲
#define RADIUS_OF_TYRE 34 //轮胎半径，单位毫米
#define LINE_SPEED_C RADIUS_OF_TYRE * 2 * 3.14

#define RELOADVALUE_1 __HAL_TIM_GetAutoreload(&ENCODER_TIM_1)    //获取自动装载值,本例中为20000
#define COUNTERNUM_1 __HAL_TIM_GetCounter(&ENCODER_TIM_1)        //获取编码器定时器中的计数值
#define RELOADVALUE_2 __HAL_TIM_GetAutoreload(&ENCODER_TIM_2)    //获取自动装载值,本例中为20000
#define COUNTERNUM_2 __HAL_TIM_GetCounter(&ENCODER_TIM_2)        //获取编码器定时器中的计数值

typedef struct _Motor
{
    int32_t lastCount;   //上一次计数值
    int32_t totalCount;  //总计数值
    int16_t overflowNum; //溢出次数
    float speed;         //电机转速
    uint8_t direct;      //旋转方向
}Motor;

void Motor_Init(void);
void Motor_Get_Speed(TIM_HandleTypeDef *htim);

#endif
