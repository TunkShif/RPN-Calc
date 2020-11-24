#ifndef RPN_CALC_STATUS_H
#define RPN_CALC_STATUS_H
#include <stdlib.h>

/*
 * Code
 * 0 for ERROR, 1 for SUCCESS
 */
typedef enum Code {
    ERROR, SUCCESS
} Code;

/*
 * Status
 * @members:
 *     Code code: the status code
 *     char *msg: the status message
 */
typedef struct Status{
    Code code;
    char *msg;
} Status;

/*
 * Status_NewStatus
 * Create a new status struct
 * This function should be considered as private
 * For creating status with custom message, use
 * Status_CustomFailedMsg() and Status_CustomSucceededMsg()
 * @param:
 *     Code code: 0 for ERROR, 1 for SUCCESS
 *     char *msg: the status message
 * @return:
 *     Status *
 */
Status *Status_NewStatus(Code code, char *msg);

/*
 * Status_MallocFailed
 * Return a status pointer with a message
 * saying that malloc function failed to
 * allocate memory
 * @return:
 *     Status *
 */
Status *Status_MallocFailed(void);

/*
 * Status_ActionSucceeded
 * Return a status pointer with a message
 * saying that certain action has been done
 * without errors
 * @return:
 *     Status *
 */
Status *Status_ActionSucceeded(void);

/*
 * Status_StackEmptyError
 * Return a status pointer with a message
 * saying that you're trying to get an
 * element from an empty stack
 * @return:
 *     Status *
 */
Status *Status_StackEmptyError(void);

/*
 * Status_ListEmptyError
 * Return a status pointer with a message
 * saying that you're trying to get an
 * element from an empty list
 * @return:
 *     Status *
 */
Status *Status_ListEmptyError(void);

/*
 * Status_OutOfIndex
 * Return a status pointer with a message
 * saying that the index is out of the
 * range of the list
 * @return:
 *     Status *
 */
Status *Status_OutOfIndex(void);

/*
 * Status_NullPointerError
 * Return a status pointer with a message
 * saying that you're trying to access data
 * from a null pointer
 * @return:
 *     Status *
 */
Status *Status_NullPointerError(void);

/*
 * Status_CustomFailedMsg
 * Return a status pointer with custom message
 * @return:
 *     Status *
 */
Status *Status_CustomFailedMsg(char *msg);

/*
 * Status_CustomFailedMsg
 * Return a status pointer with custom message
 * @return:
 *     Status *
 */
Status *Status_CustomSucceededMsg(char *msg);
#endif
