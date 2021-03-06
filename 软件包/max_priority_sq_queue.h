#ifndef __Max_PRIORITY_SQ_QUEUE_H__
#define __Max_PRIORITY_SQ_QUEUE_H__

#include "sq_queue.h"				// 循环队列类模板

// 最大优先循环队列类模板
template<class ElemType>
class MaxPrioritySqQueue: public SqQueue<ElemType> 
{
public:
//  重载入队操作声明:
	StatusCode InQueue(const ElemType &e);			// 重载入队操作
};

// 最大优先循环队列类模板的实现部分
template<class ElemType>
StatusCode MaxPrioritySqQueue<ElemType>::InQueue(const ElemType &e)
// 操作结果：如果队列已满，返回OVER_FLOW,
//	否则插入元素e为新的队尾，返回SUCCESS
{
	if (SqQueue<ElemType>::Full())
	{	// 队列已满
		return OVER_FLOW;
	}
	else
	{	// 队列未满，入队成功
		int curPosition = SqQueue<ElemType>::front;
		while (curPosition != SqQueue<ElemType>::rear && 
			SqQueue<ElemType>::elems[curPosition] >= e)
		{	// 将所有不小于e的元素向前移一个位置
			SqQueue<ElemType>::elems[(curPosition - 1 + SqQueue<ElemType>::maxSize) 
				% SqQueue<ElemType>::maxSize] = SqQueue<ElemType>::elems[curPosition];
				// elems[curPosition]前移一个位置
			curPosition = (curPosition + 1) % SqQueue<ElemType>::maxSize;	
				// curPosition指向下一元素
		}

		SqQueue<ElemType>::elems[(curPosition - 1 + SqQueue<ElemType>::maxSize) % 
			SqQueue<ElemType>::maxSize] = e;
			// curPosition的前一位置为e的插入位置
		SqQueue<ElemType>::front = (SqQueue<ElemType>::front - 1 + 
			SqQueue<ElemType>::maxSize) % SqQueue<ElemType>::maxSize;	
		// front移向前一位置

		return SUCCESS;
	}
}

#endif