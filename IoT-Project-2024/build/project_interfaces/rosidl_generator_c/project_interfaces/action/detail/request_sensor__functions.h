// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from project_interfaces:action/RequestSensor.idl
// generated code does not contain a copyright notice

#ifndef PROJECT_INTERFACES__ACTION__DETAIL__REQUEST_SENSOR__FUNCTIONS_H_
#define PROJECT_INTERFACES__ACTION__DETAIL__REQUEST_SENSOR__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "project_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "project_interfaces/action/detail/request_sensor__struct.h"

/// Initialize action/RequestSensor message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * project_interfaces__action__RequestSensor_Goal
 * )) before or use
 * project_interfaces__action__RequestSensor_Goal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_Goal__init(project_interfaces__action__RequestSensor_Goal * msg);

/// Finalize action/RequestSensor message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
void
project_interfaces__action__RequestSensor_Goal__fini(project_interfaces__action__RequestSensor_Goal * msg);

/// Create action/RequestSensor message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * project_interfaces__action__RequestSensor_Goal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
project_interfaces__action__RequestSensor_Goal *
project_interfaces__action__RequestSensor_Goal__create();

/// Destroy action/RequestSensor message.
/**
 * It calls
 * project_interfaces__action__RequestSensor_Goal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
void
project_interfaces__action__RequestSensor_Goal__destroy(project_interfaces__action__RequestSensor_Goal * msg);

/// Check for action/RequestSensor message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_Goal__are_equal(const project_interfaces__action__RequestSensor_Goal * lhs, const project_interfaces__action__RequestSensor_Goal * rhs);

/// Copy a action/RequestSensor message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_Goal__copy(
  const project_interfaces__action__RequestSensor_Goal * input,
  project_interfaces__action__RequestSensor_Goal * output);

/// Initialize array of action/RequestSensor messages.
/**
 * It allocates the memory for the number of elements and calls
 * project_interfaces__action__RequestSensor_Goal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_Goal__Sequence__init(project_interfaces__action__RequestSensor_Goal__Sequence * array, size_t size);

/// Finalize array of action/RequestSensor messages.
/**
 * It calls
 * project_interfaces__action__RequestSensor_Goal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
void
project_interfaces__action__RequestSensor_Goal__Sequence__fini(project_interfaces__action__RequestSensor_Goal__Sequence * array);

/// Create array of action/RequestSensor messages.
/**
 * It allocates the memory for the array and calls
 * project_interfaces__action__RequestSensor_Goal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
project_interfaces__action__RequestSensor_Goal__Sequence *
project_interfaces__action__RequestSensor_Goal__Sequence__create(size_t size);

/// Destroy array of action/RequestSensor messages.
/**
 * It calls
 * project_interfaces__action__RequestSensor_Goal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
void
project_interfaces__action__RequestSensor_Goal__Sequence__destroy(project_interfaces__action__RequestSensor_Goal__Sequence * array);

/// Check for action/RequestSensor message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_Goal__Sequence__are_equal(const project_interfaces__action__RequestSensor_Goal__Sequence * lhs, const project_interfaces__action__RequestSensor_Goal__Sequence * rhs);

/// Copy an array of action/RequestSensor messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_Goal__Sequence__copy(
  const project_interfaces__action__RequestSensor_Goal__Sequence * input,
  project_interfaces__action__RequestSensor_Goal__Sequence * output);

/// Initialize action/RequestSensor message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * project_interfaces__action__RequestSensor_Result
 * )) before or use
 * project_interfaces__action__RequestSensor_Result__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_Result__init(project_interfaces__action__RequestSensor_Result * msg);

/// Finalize action/RequestSensor message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
void
project_interfaces__action__RequestSensor_Result__fini(project_interfaces__action__RequestSensor_Result * msg);

/// Create action/RequestSensor message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * project_interfaces__action__RequestSensor_Result__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
project_interfaces__action__RequestSensor_Result *
project_interfaces__action__RequestSensor_Result__create();

/// Destroy action/RequestSensor message.
/**
 * It calls
 * project_interfaces__action__RequestSensor_Result__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
void
project_interfaces__action__RequestSensor_Result__destroy(project_interfaces__action__RequestSensor_Result * msg);

/// Check for action/RequestSensor message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_Result__are_equal(const project_interfaces__action__RequestSensor_Result * lhs, const project_interfaces__action__RequestSensor_Result * rhs);

/// Copy a action/RequestSensor message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_Result__copy(
  const project_interfaces__action__RequestSensor_Result * input,
  project_interfaces__action__RequestSensor_Result * output);

/// Initialize array of action/RequestSensor messages.
/**
 * It allocates the memory for the number of elements and calls
 * project_interfaces__action__RequestSensor_Result__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_Result__Sequence__init(project_interfaces__action__RequestSensor_Result__Sequence * array, size_t size);

/// Finalize array of action/RequestSensor messages.
/**
 * It calls
 * project_interfaces__action__RequestSensor_Result__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
void
project_interfaces__action__RequestSensor_Result__Sequence__fini(project_interfaces__action__RequestSensor_Result__Sequence * array);

/// Create array of action/RequestSensor messages.
/**
 * It allocates the memory for the array and calls
 * project_interfaces__action__RequestSensor_Result__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
project_interfaces__action__RequestSensor_Result__Sequence *
project_interfaces__action__RequestSensor_Result__Sequence__create(size_t size);

/// Destroy array of action/RequestSensor messages.
/**
 * It calls
 * project_interfaces__action__RequestSensor_Result__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
void
project_interfaces__action__RequestSensor_Result__Sequence__destroy(project_interfaces__action__RequestSensor_Result__Sequence * array);

/// Check for action/RequestSensor message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_Result__Sequence__are_equal(const project_interfaces__action__RequestSensor_Result__Sequence * lhs, const project_interfaces__action__RequestSensor_Result__Sequence * rhs);

/// Copy an array of action/RequestSensor messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_Result__Sequence__copy(
  const project_interfaces__action__RequestSensor_Result__Sequence * input,
  project_interfaces__action__RequestSensor_Result__Sequence * output);

/// Initialize action/RequestSensor message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * project_interfaces__action__RequestSensor_Feedback
 * )) before or use
 * project_interfaces__action__RequestSensor_Feedback__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_Feedback__init(project_interfaces__action__RequestSensor_Feedback * msg);

/// Finalize action/RequestSensor message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
void
project_interfaces__action__RequestSensor_Feedback__fini(project_interfaces__action__RequestSensor_Feedback * msg);

/// Create action/RequestSensor message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * project_interfaces__action__RequestSensor_Feedback__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
project_interfaces__action__RequestSensor_Feedback *
project_interfaces__action__RequestSensor_Feedback__create();

/// Destroy action/RequestSensor message.
/**
 * It calls
 * project_interfaces__action__RequestSensor_Feedback__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
void
project_interfaces__action__RequestSensor_Feedback__destroy(project_interfaces__action__RequestSensor_Feedback * msg);

/// Check for action/RequestSensor message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_Feedback__are_equal(const project_interfaces__action__RequestSensor_Feedback * lhs, const project_interfaces__action__RequestSensor_Feedback * rhs);

/// Copy a action/RequestSensor message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_Feedback__copy(
  const project_interfaces__action__RequestSensor_Feedback * input,
  project_interfaces__action__RequestSensor_Feedback * output);

/// Initialize array of action/RequestSensor messages.
/**
 * It allocates the memory for the number of elements and calls
 * project_interfaces__action__RequestSensor_Feedback__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_Feedback__Sequence__init(project_interfaces__action__RequestSensor_Feedback__Sequence * array, size_t size);

/// Finalize array of action/RequestSensor messages.
/**
 * It calls
 * project_interfaces__action__RequestSensor_Feedback__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
void
project_interfaces__action__RequestSensor_Feedback__Sequence__fini(project_interfaces__action__RequestSensor_Feedback__Sequence * array);

/// Create array of action/RequestSensor messages.
/**
 * It allocates the memory for the array and calls
 * project_interfaces__action__RequestSensor_Feedback__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
project_interfaces__action__RequestSensor_Feedback__Sequence *
project_interfaces__action__RequestSensor_Feedback__Sequence__create(size_t size);

/// Destroy array of action/RequestSensor messages.
/**
 * It calls
 * project_interfaces__action__RequestSensor_Feedback__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
void
project_interfaces__action__RequestSensor_Feedback__Sequence__destroy(project_interfaces__action__RequestSensor_Feedback__Sequence * array);

/// Check for action/RequestSensor message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_Feedback__Sequence__are_equal(const project_interfaces__action__RequestSensor_Feedback__Sequence * lhs, const project_interfaces__action__RequestSensor_Feedback__Sequence * rhs);

/// Copy an array of action/RequestSensor messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_Feedback__Sequence__copy(
  const project_interfaces__action__RequestSensor_Feedback__Sequence * input,
  project_interfaces__action__RequestSensor_Feedback__Sequence * output);

/// Initialize action/RequestSensor message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * project_interfaces__action__RequestSensor_SendGoal_Request
 * )) before or use
 * project_interfaces__action__RequestSensor_SendGoal_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_SendGoal_Request__init(project_interfaces__action__RequestSensor_SendGoal_Request * msg);

/// Finalize action/RequestSensor message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
void
project_interfaces__action__RequestSensor_SendGoal_Request__fini(project_interfaces__action__RequestSensor_SendGoal_Request * msg);

/// Create action/RequestSensor message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * project_interfaces__action__RequestSensor_SendGoal_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
project_interfaces__action__RequestSensor_SendGoal_Request *
project_interfaces__action__RequestSensor_SendGoal_Request__create();

/// Destroy action/RequestSensor message.
/**
 * It calls
 * project_interfaces__action__RequestSensor_SendGoal_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
void
project_interfaces__action__RequestSensor_SendGoal_Request__destroy(project_interfaces__action__RequestSensor_SendGoal_Request * msg);

/// Check for action/RequestSensor message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_SendGoal_Request__are_equal(const project_interfaces__action__RequestSensor_SendGoal_Request * lhs, const project_interfaces__action__RequestSensor_SendGoal_Request * rhs);

/// Copy a action/RequestSensor message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_SendGoal_Request__copy(
  const project_interfaces__action__RequestSensor_SendGoal_Request * input,
  project_interfaces__action__RequestSensor_SendGoal_Request * output);

/// Initialize array of action/RequestSensor messages.
/**
 * It allocates the memory for the number of elements and calls
 * project_interfaces__action__RequestSensor_SendGoal_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_SendGoal_Request__Sequence__init(project_interfaces__action__RequestSensor_SendGoal_Request__Sequence * array, size_t size);

/// Finalize array of action/RequestSensor messages.
/**
 * It calls
 * project_interfaces__action__RequestSensor_SendGoal_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
void
project_interfaces__action__RequestSensor_SendGoal_Request__Sequence__fini(project_interfaces__action__RequestSensor_SendGoal_Request__Sequence * array);

/// Create array of action/RequestSensor messages.
/**
 * It allocates the memory for the array and calls
 * project_interfaces__action__RequestSensor_SendGoal_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
project_interfaces__action__RequestSensor_SendGoal_Request__Sequence *
project_interfaces__action__RequestSensor_SendGoal_Request__Sequence__create(size_t size);

/// Destroy array of action/RequestSensor messages.
/**
 * It calls
 * project_interfaces__action__RequestSensor_SendGoal_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
void
project_interfaces__action__RequestSensor_SendGoal_Request__Sequence__destroy(project_interfaces__action__RequestSensor_SendGoal_Request__Sequence * array);

/// Check for action/RequestSensor message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_SendGoal_Request__Sequence__are_equal(const project_interfaces__action__RequestSensor_SendGoal_Request__Sequence * lhs, const project_interfaces__action__RequestSensor_SendGoal_Request__Sequence * rhs);

/// Copy an array of action/RequestSensor messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_SendGoal_Request__Sequence__copy(
  const project_interfaces__action__RequestSensor_SendGoal_Request__Sequence * input,
  project_interfaces__action__RequestSensor_SendGoal_Request__Sequence * output);

/// Initialize action/RequestSensor message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * project_interfaces__action__RequestSensor_SendGoal_Response
 * )) before or use
 * project_interfaces__action__RequestSensor_SendGoal_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_SendGoal_Response__init(project_interfaces__action__RequestSensor_SendGoal_Response * msg);

/// Finalize action/RequestSensor message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
void
project_interfaces__action__RequestSensor_SendGoal_Response__fini(project_interfaces__action__RequestSensor_SendGoal_Response * msg);

/// Create action/RequestSensor message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * project_interfaces__action__RequestSensor_SendGoal_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
project_interfaces__action__RequestSensor_SendGoal_Response *
project_interfaces__action__RequestSensor_SendGoal_Response__create();

/// Destroy action/RequestSensor message.
/**
 * It calls
 * project_interfaces__action__RequestSensor_SendGoal_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
void
project_interfaces__action__RequestSensor_SendGoal_Response__destroy(project_interfaces__action__RequestSensor_SendGoal_Response * msg);

/// Check for action/RequestSensor message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_SendGoal_Response__are_equal(const project_interfaces__action__RequestSensor_SendGoal_Response * lhs, const project_interfaces__action__RequestSensor_SendGoal_Response * rhs);

/// Copy a action/RequestSensor message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_SendGoal_Response__copy(
  const project_interfaces__action__RequestSensor_SendGoal_Response * input,
  project_interfaces__action__RequestSensor_SendGoal_Response * output);

/// Initialize array of action/RequestSensor messages.
/**
 * It allocates the memory for the number of elements and calls
 * project_interfaces__action__RequestSensor_SendGoal_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_SendGoal_Response__Sequence__init(project_interfaces__action__RequestSensor_SendGoal_Response__Sequence * array, size_t size);

/// Finalize array of action/RequestSensor messages.
/**
 * It calls
 * project_interfaces__action__RequestSensor_SendGoal_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
void
project_interfaces__action__RequestSensor_SendGoal_Response__Sequence__fini(project_interfaces__action__RequestSensor_SendGoal_Response__Sequence * array);

/// Create array of action/RequestSensor messages.
/**
 * It allocates the memory for the array and calls
 * project_interfaces__action__RequestSensor_SendGoal_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
project_interfaces__action__RequestSensor_SendGoal_Response__Sequence *
project_interfaces__action__RequestSensor_SendGoal_Response__Sequence__create(size_t size);

/// Destroy array of action/RequestSensor messages.
/**
 * It calls
 * project_interfaces__action__RequestSensor_SendGoal_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
void
project_interfaces__action__RequestSensor_SendGoal_Response__Sequence__destroy(project_interfaces__action__RequestSensor_SendGoal_Response__Sequence * array);

/// Check for action/RequestSensor message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_SendGoal_Response__Sequence__are_equal(const project_interfaces__action__RequestSensor_SendGoal_Response__Sequence * lhs, const project_interfaces__action__RequestSensor_SendGoal_Response__Sequence * rhs);

/// Copy an array of action/RequestSensor messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_SendGoal_Response__Sequence__copy(
  const project_interfaces__action__RequestSensor_SendGoal_Response__Sequence * input,
  project_interfaces__action__RequestSensor_SendGoal_Response__Sequence * output);

/// Initialize action/RequestSensor message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * project_interfaces__action__RequestSensor_GetResult_Request
 * )) before or use
 * project_interfaces__action__RequestSensor_GetResult_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_GetResult_Request__init(project_interfaces__action__RequestSensor_GetResult_Request * msg);

/// Finalize action/RequestSensor message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
void
project_interfaces__action__RequestSensor_GetResult_Request__fini(project_interfaces__action__RequestSensor_GetResult_Request * msg);

/// Create action/RequestSensor message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * project_interfaces__action__RequestSensor_GetResult_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
project_interfaces__action__RequestSensor_GetResult_Request *
project_interfaces__action__RequestSensor_GetResult_Request__create();

/// Destroy action/RequestSensor message.
/**
 * It calls
 * project_interfaces__action__RequestSensor_GetResult_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
void
project_interfaces__action__RequestSensor_GetResult_Request__destroy(project_interfaces__action__RequestSensor_GetResult_Request * msg);

/// Check for action/RequestSensor message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_GetResult_Request__are_equal(const project_interfaces__action__RequestSensor_GetResult_Request * lhs, const project_interfaces__action__RequestSensor_GetResult_Request * rhs);

/// Copy a action/RequestSensor message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_GetResult_Request__copy(
  const project_interfaces__action__RequestSensor_GetResult_Request * input,
  project_interfaces__action__RequestSensor_GetResult_Request * output);

/// Initialize array of action/RequestSensor messages.
/**
 * It allocates the memory for the number of elements and calls
 * project_interfaces__action__RequestSensor_GetResult_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_GetResult_Request__Sequence__init(project_interfaces__action__RequestSensor_GetResult_Request__Sequence * array, size_t size);

/// Finalize array of action/RequestSensor messages.
/**
 * It calls
 * project_interfaces__action__RequestSensor_GetResult_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
void
project_interfaces__action__RequestSensor_GetResult_Request__Sequence__fini(project_interfaces__action__RequestSensor_GetResult_Request__Sequence * array);

/// Create array of action/RequestSensor messages.
/**
 * It allocates the memory for the array and calls
 * project_interfaces__action__RequestSensor_GetResult_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
project_interfaces__action__RequestSensor_GetResult_Request__Sequence *
project_interfaces__action__RequestSensor_GetResult_Request__Sequence__create(size_t size);

/// Destroy array of action/RequestSensor messages.
/**
 * It calls
 * project_interfaces__action__RequestSensor_GetResult_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
void
project_interfaces__action__RequestSensor_GetResult_Request__Sequence__destroy(project_interfaces__action__RequestSensor_GetResult_Request__Sequence * array);

/// Check for action/RequestSensor message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_GetResult_Request__Sequence__are_equal(const project_interfaces__action__RequestSensor_GetResult_Request__Sequence * lhs, const project_interfaces__action__RequestSensor_GetResult_Request__Sequence * rhs);

/// Copy an array of action/RequestSensor messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_GetResult_Request__Sequence__copy(
  const project_interfaces__action__RequestSensor_GetResult_Request__Sequence * input,
  project_interfaces__action__RequestSensor_GetResult_Request__Sequence * output);

/// Initialize action/RequestSensor message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * project_interfaces__action__RequestSensor_GetResult_Response
 * )) before or use
 * project_interfaces__action__RequestSensor_GetResult_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_GetResult_Response__init(project_interfaces__action__RequestSensor_GetResult_Response * msg);

/// Finalize action/RequestSensor message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
void
project_interfaces__action__RequestSensor_GetResult_Response__fini(project_interfaces__action__RequestSensor_GetResult_Response * msg);

/// Create action/RequestSensor message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * project_interfaces__action__RequestSensor_GetResult_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
project_interfaces__action__RequestSensor_GetResult_Response *
project_interfaces__action__RequestSensor_GetResult_Response__create();

/// Destroy action/RequestSensor message.
/**
 * It calls
 * project_interfaces__action__RequestSensor_GetResult_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
void
project_interfaces__action__RequestSensor_GetResult_Response__destroy(project_interfaces__action__RequestSensor_GetResult_Response * msg);

/// Check for action/RequestSensor message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_GetResult_Response__are_equal(const project_interfaces__action__RequestSensor_GetResult_Response * lhs, const project_interfaces__action__RequestSensor_GetResult_Response * rhs);

/// Copy a action/RequestSensor message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_GetResult_Response__copy(
  const project_interfaces__action__RequestSensor_GetResult_Response * input,
  project_interfaces__action__RequestSensor_GetResult_Response * output);

/// Initialize array of action/RequestSensor messages.
/**
 * It allocates the memory for the number of elements and calls
 * project_interfaces__action__RequestSensor_GetResult_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_GetResult_Response__Sequence__init(project_interfaces__action__RequestSensor_GetResult_Response__Sequence * array, size_t size);

/// Finalize array of action/RequestSensor messages.
/**
 * It calls
 * project_interfaces__action__RequestSensor_GetResult_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
void
project_interfaces__action__RequestSensor_GetResult_Response__Sequence__fini(project_interfaces__action__RequestSensor_GetResult_Response__Sequence * array);

/// Create array of action/RequestSensor messages.
/**
 * It allocates the memory for the array and calls
 * project_interfaces__action__RequestSensor_GetResult_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
project_interfaces__action__RequestSensor_GetResult_Response__Sequence *
project_interfaces__action__RequestSensor_GetResult_Response__Sequence__create(size_t size);

/// Destroy array of action/RequestSensor messages.
/**
 * It calls
 * project_interfaces__action__RequestSensor_GetResult_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
void
project_interfaces__action__RequestSensor_GetResult_Response__Sequence__destroy(project_interfaces__action__RequestSensor_GetResult_Response__Sequence * array);

/// Check for action/RequestSensor message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_GetResult_Response__Sequence__are_equal(const project_interfaces__action__RequestSensor_GetResult_Response__Sequence * lhs, const project_interfaces__action__RequestSensor_GetResult_Response__Sequence * rhs);

/// Copy an array of action/RequestSensor messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_GetResult_Response__Sequence__copy(
  const project_interfaces__action__RequestSensor_GetResult_Response__Sequence * input,
  project_interfaces__action__RequestSensor_GetResult_Response__Sequence * output);

/// Initialize action/RequestSensor message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * project_interfaces__action__RequestSensor_FeedbackMessage
 * )) before or use
 * project_interfaces__action__RequestSensor_FeedbackMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_FeedbackMessage__init(project_interfaces__action__RequestSensor_FeedbackMessage * msg);

/// Finalize action/RequestSensor message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
void
project_interfaces__action__RequestSensor_FeedbackMessage__fini(project_interfaces__action__RequestSensor_FeedbackMessage * msg);

/// Create action/RequestSensor message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * project_interfaces__action__RequestSensor_FeedbackMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
project_interfaces__action__RequestSensor_FeedbackMessage *
project_interfaces__action__RequestSensor_FeedbackMessage__create();

/// Destroy action/RequestSensor message.
/**
 * It calls
 * project_interfaces__action__RequestSensor_FeedbackMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
void
project_interfaces__action__RequestSensor_FeedbackMessage__destroy(project_interfaces__action__RequestSensor_FeedbackMessage * msg);

/// Check for action/RequestSensor message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_FeedbackMessage__are_equal(const project_interfaces__action__RequestSensor_FeedbackMessage * lhs, const project_interfaces__action__RequestSensor_FeedbackMessage * rhs);

/// Copy a action/RequestSensor message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_FeedbackMessage__copy(
  const project_interfaces__action__RequestSensor_FeedbackMessage * input,
  project_interfaces__action__RequestSensor_FeedbackMessage * output);

/// Initialize array of action/RequestSensor messages.
/**
 * It allocates the memory for the number of elements and calls
 * project_interfaces__action__RequestSensor_FeedbackMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_FeedbackMessage__Sequence__init(project_interfaces__action__RequestSensor_FeedbackMessage__Sequence * array, size_t size);

/// Finalize array of action/RequestSensor messages.
/**
 * It calls
 * project_interfaces__action__RequestSensor_FeedbackMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
void
project_interfaces__action__RequestSensor_FeedbackMessage__Sequence__fini(project_interfaces__action__RequestSensor_FeedbackMessage__Sequence * array);

/// Create array of action/RequestSensor messages.
/**
 * It allocates the memory for the array and calls
 * project_interfaces__action__RequestSensor_FeedbackMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
project_interfaces__action__RequestSensor_FeedbackMessage__Sequence *
project_interfaces__action__RequestSensor_FeedbackMessage__Sequence__create(size_t size);

/// Destroy array of action/RequestSensor messages.
/**
 * It calls
 * project_interfaces__action__RequestSensor_FeedbackMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
void
project_interfaces__action__RequestSensor_FeedbackMessage__Sequence__destroy(project_interfaces__action__RequestSensor_FeedbackMessage__Sequence * array);

/// Check for action/RequestSensor message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_FeedbackMessage__Sequence__are_equal(const project_interfaces__action__RequestSensor_FeedbackMessage__Sequence * lhs, const project_interfaces__action__RequestSensor_FeedbackMessage__Sequence * rhs);

/// Copy an array of action/RequestSensor messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_project_interfaces
bool
project_interfaces__action__RequestSensor_FeedbackMessage__Sequence__copy(
  const project_interfaces__action__RequestSensor_FeedbackMessage__Sequence * input,
  project_interfaces__action__RequestSensor_FeedbackMessage__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // PROJECT_INTERFACES__ACTION__DETAIL__REQUEST_SENSOR__FUNCTIONS_H_
