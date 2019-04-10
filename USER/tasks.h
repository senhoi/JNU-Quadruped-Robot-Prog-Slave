#ifndef TASK_H
#define TASK_H

#include "sys.h"
#include "usart.h"
#include "led.h"
#include "lcd.h"
#include "can.h"
#include "beep.h"
#include "key.h"
#include "timer.h"
#include "interact.h"
#include "actuator.h"
#include "display.h"
#include "sbus.h"
#include "remote.h"

extern unsigned int LowPirorityTaskFlag;
extern int ActrHomingError;
extern int ActrHomingCorrect;
extern int ActrHomingErrorID[12];
extern int ReportTaskFlag; //��ִ�������Ϳ�������ǰ�رմ˱�־λ�Խ�ֹ��ʱ�������񣬷�ֹ���߸���

typedef enum task_flag
{
	TASK_FLAG_KEY = 0,
	TASK_FLAG_REPORT_POS,
	TASK_FLAG_REPORT_VEL,
	TASK_FLAG_REPORT_CUR,
	TASK_FLAG_REPORT_EXECPTION,
	TASK_FLAG_REPORT_ALL,
	TASK_FLAG_UPLOAD,
	TASK_FLAG_CONTROL,
} TaskFlagTypedef;

#define TASK_SET_FLAG(flag) (LowPirorityTaskFlag |= (0x0001 << (unsigned int)flag))
#define TASK_RESET_FLAG(flag) (LowPirorityTaskFlag &= (~(0x0001 << (unsigned int)flag)))
#define TASK_SEARCH_FLAG(flag) (LowPirorityTaskFlag & (0x0001 << (unsigned int)flag))
#define TASK_STOP_REGULAR_REPORT (ReportTaskFlag = 0)
#define TASK_BEGIN_REGULAR_REPORT (ReportTaskFlag = 1)
#define TASK_CHECK_REGULAR_REPORT_FLAG (ReportTaskFlag == 1)

void InitTask(void);
void KeyTask(void);
void UploadTask(void);
void ControlTask(void);
void HandleLowPirorityTask(void);
void SubmissiveCtrlTask(uint8_t TriggerData);

#endif