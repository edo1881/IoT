// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from project_interfaces:action/RequestSensor.idl
// generated code does not contain a copyright notice

#ifndef PROJECT_INTERFACES__ACTION__DETAIL__REQUEST_SENSOR__STRUCT_H_
#define PROJECT_INTERFACES__ACTION__DETAIL__REQUEST_SENSOR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'bs_request'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/RequestSensor in the package project_interfaces.
typedef struct project_interfaces__action__RequestSensor_Goal
{
  rosidl_runtime_c__String bs_request;
} project_interfaces__action__RequestSensor_Goal;

// Struct for a sequence of project_interfaces__action__RequestSensor_Goal.
typedef struct project_interfaces__action__RequestSensor_Goal__Sequence
{
  project_interfaces__action__RequestSensor_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} project_interfaces__action__RequestSensor_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'balloons_response'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/RequestSensor in the package project_interfaces.
typedef struct project_interfaces__action__RequestSensor_Result
{
  rosidl_runtime_c__String balloons_response;
} project_interfaces__action__RequestSensor_Result;

// Struct for a sequence of project_interfaces__action__RequestSensor_Result.
typedef struct project_interfaces__action__RequestSensor_Result__Sequence
{
  project_interfaces__action__RequestSensor_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} project_interfaces__action__RequestSensor_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'feed'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/RequestSensor in the package project_interfaces.
typedef struct project_interfaces__action__RequestSensor_Feedback
{
  rosidl_runtime_c__String feed;
} project_interfaces__action__RequestSensor_Feedback;

// Struct for a sequence of project_interfaces__action__RequestSensor_Feedback.
typedef struct project_interfaces__action__RequestSensor_Feedback__Sequence
{
  project_interfaces__action__RequestSensor_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} project_interfaces__action__RequestSensor_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "project_interfaces/action/detail/request_sensor__struct.h"

/// Struct defined in action/RequestSensor in the package project_interfaces.
typedef struct project_interfaces__action__RequestSensor_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  project_interfaces__action__RequestSensor_Goal goal;
} project_interfaces__action__RequestSensor_SendGoal_Request;

// Struct for a sequence of project_interfaces__action__RequestSensor_SendGoal_Request.
typedef struct project_interfaces__action__RequestSensor_SendGoal_Request__Sequence
{
  project_interfaces__action__RequestSensor_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} project_interfaces__action__RequestSensor_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/RequestSensor in the package project_interfaces.
typedef struct project_interfaces__action__RequestSensor_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} project_interfaces__action__RequestSensor_SendGoal_Response;

// Struct for a sequence of project_interfaces__action__RequestSensor_SendGoal_Response.
typedef struct project_interfaces__action__RequestSensor_SendGoal_Response__Sequence
{
  project_interfaces__action__RequestSensor_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} project_interfaces__action__RequestSensor_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/RequestSensor in the package project_interfaces.
typedef struct project_interfaces__action__RequestSensor_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} project_interfaces__action__RequestSensor_GetResult_Request;

// Struct for a sequence of project_interfaces__action__RequestSensor_GetResult_Request.
typedef struct project_interfaces__action__RequestSensor_GetResult_Request__Sequence
{
  project_interfaces__action__RequestSensor_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} project_interfaces__action__RequestSensor_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "project_interfaces/action/detail/request_sensor__struct.h"

/// Struct defined in action/RequestSensor in the package project_interfaces.
typedef struct project_interfaces__action__RequestSensor_GetResult_Response
{
  int8_t status;
  project_interfaces__action__RequestSensor_Result result;
} project_interfaces__action__RequestSensor_GetResult_Response;

// Struct for a sequence of project_interfaces__action__RequestSensor_GetResult_Response.
typedef struct project_interfaces__action__RequestSensor_GetResult_Response__Sequence
{
  project_interfaces__action__RequestSensor_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} project_interfaces__action__RequestSensor_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "project_interfaces/action/detail/request_sensor__struct.h"

/// Struct defined in action/RequestSensor in the package project_interfaces.
typedef struct project_interfaces__action__RequestSensor_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  project_interfaces__action__RequestSensor_Feedback feedback;
} project_interfaces__action__RequestSensor_FeedbackMessage;

// Struct for a sequence of project_interfaces__action__RequestSensor_FeedbackMessage.
typedef struct project_interfaces__action__RequestSensor_FeedbackMessage__Sequence
{
  project_interfaces__action__RequestSensor_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} project_interfaces__action__RequestSensor_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PROJECT_INTERFACES__ACTION__DETAIL__REQUEST_SENSOR__STRUCT_H_
