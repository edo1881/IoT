// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from project_interfaces:action/RequestSensor.idl
// generated code does not contain a copyright notice

#ifndef PROJECT_INTERFACES__ACTION__DETAIL__REQUEST_SENSOR__TRAITS_HPP_
#define PROJECT_INTERFACES__ACTION__DETAIL__REQUEST_SENSOR__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "project_interfaces/action/detail/request_sensor__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace project_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const RequestSensor_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: bs_request
  {
    out << "bs_request: ";
    rosidl_generator_traits::value_to_yaml(msg.bs_request, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RequestSensor_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: bs_request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bs_request: ";
    rosidl_generator_traits::value_to_yaml(msg.bs_request, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RequestSensor_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace project_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use project_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const project_interfaces::action::RequestSensor_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  project_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use project_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const project_interfaces::action::RequestSensor_Goal & msg)
{
  return project_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<project_interfaces::action::RequestSensor_Goal>()
{
  return "project_interfaces::action::RequestSensor_Goal";
}

template<>
inline const char * name<project_interfaces::action::RequestSensor_Goal>()
{
  return "project_interfaces/action/RequestSensor_Goal";
}

template<>
struct has_fixed_size<project_interfaces::action::RequestSensor_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<project_interfaces::action::RequestSensor_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<project_interfaces::action::RequestSensor_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace project_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const RequestSensor_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: balloons_response
  {
    out << "balloons_response: ";
    rosidl_generator_traits::value_to_yaml(msg.balloons_response, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RequestSensor_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: balloons_response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "balloons_response: ";
    rosidl_generator_traits::value_to_yaml(msg.balloons_response, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RequestSensor_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace project_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use project_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const project_interfaces::action::RequestSensor_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  project_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use project_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const project_interfaces::action::RequestSensor_Result & msg)
{
  return project_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<project_interfaces::action::RequestSensor_Result>()
{
  return "project_interfaces::action::RequestSensor_Result";
}

template<>
inline const char * name<project_interfaces::action::RequestSensor_Result>()
{
  return "project_interfaces/action/RequestSensor_Result";
}

template<>
struct has_fixed_size<project_interfaces::action::RequestSensor_Result>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<project_interfaces::action::RequestSensor_Result>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<project_interfaces::action::RequestSensor_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace project_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const RequestSensor_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: feed
  {
    out << "feed: ";
    rosidl_generator_traits::value_to_yaml(msg.feed, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RequestSensor_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: feed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feed: ";
    rosidl_generator_traits::value_to_yaml(msg.feed, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RequestSensor_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace project_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use project_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const project_interfaces::action::RequestSensor_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  project_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use project_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const project_interfaces::action::RequestSensor_Feedback & msg)
{
  return project_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<project_interfaces::action::RequestSensor_Feedback>()
{
  return "project_interfaces::action::RequestSensor_Feedback";
}

template<>
inline const char * name<project_interfaces::action::RequestSensor_Feedback>()
{
  return "project_interfaces/action/RequestSensor_Feedback";
}

template<>
struct has_fixed_size<project_interfaces::action::RequestSensor_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<project_interfaces::action::RequestSensor_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<project_interfaces::action::RequestSensor_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "project_interfaces/action/detail/request_sensor__traits.hpp"

namespace project_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const RequestSensor_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RequestSensor_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RequestSensor_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace project_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use project_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const project_interfaces::action::RequestSensor_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  project_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use project_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const project_interfaces::action::RequestSensor_SendGoal_Request & msg)
{
  return project_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<project_interfaces::action::RequestSensor_SendGoal_Request>()
{
  return "project_interfaces::action::RequestSensor_SendGoal_Request";
}

template<>
inline const char * name<project_interfaces::action::RequestSensor_SendGoal_Request>()
{
  return "project_interfaces/action/RequestSensor_SendGoal_Request";
}

template<>
struct has_fixed_size<project_interfaces::action::RequestSensor_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<project_interfaces::action::RequestSensor_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<project_interfaces::action::RequestSensor_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<project_interfaces::action::RequestSensor_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<project_interfaces::action::RequestSensor_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace project_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const RequestSensor_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RequestSensor_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RequestSensor_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace project_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use project_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const project_interfaces::action::RequestSensor_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  project_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use project_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const project_interfaces::action::RequestSensor_SendGoal_Response & msg)
{
  return project_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<project_interfaces::action::RequestSensor_SendGoal_Response>()
{
  return "project_interfaces::action::RequestSensor_SendGoal_Response";
}

template<>
inline const char * name<project_interfaces::action::RequestSensor_SendGoal_Response>()
{
  return "project_interfaces/action/RequestSensor_SendGoal_Response";
}

template<>
struct has_fixed_size<project_interfaces::action::RequestSensor_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<project_interfaces::action::RequestSensor_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<project_interfaces::action::RequestSensor_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<project_interfaces::action::RequestSensor_SendGoal>()
{
  return "project_interfaces::action::RequestSensor_SendGoal";
}

template<>
inline const char * name<project_interfaces::action::RequestSensor_SendGoal>()
{
  return "project_interfaces/action/RequestSensor_SendGoal";
}

template<>
struct has_fixed_size<project_interfaces::action::RequestSensor_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<project_interfaces::action::RequestSensor_SendGoal_Request>::value &&
    has_fixed_size<project_interfaces::action::RequestSensor_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<project_interfaces::action::RequestSensor_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<project_interfaces::action::RequestSensor_SendGoal_Request>::value &&
    has_bounded_size<project_interfaces::action::RequestSensor_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<project_interfaces::action::RequestSensor_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<project_interfaces::action::RequestSensor_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<project_interfaces::action::RequestSensor_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace project_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const RequestSensor_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RequestSensor_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RequestSensor_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace project_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use project_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const project_interfaces::action::RequestSensor_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  project_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use project_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const project_interfaces::action::RequestSensor_GetResult_Request & msg)
{
  return project_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<project_interfaces::action::RequestSensor_GetResult_Request>()
{
  return "project_interfaces::action::RequestSensor_GetResult_Request";
}

template<>
inline const char * name<project_interfaces::action::RequestSensor_GetResult_Request>()
{
  return "project_interfaces/action/RequestSensor_GetResult_Request";
}

template<>
struct has_fixed_size<project_interfaces::action::RequestSensor_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<project_interfaces::action::RequestSensor_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<project_interfaces::action::RequestSensor_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "project_interfaces/action/detail/request_sensor__traits.hpp"

namespace project_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const RequestSensor_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RequestSensor_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RequestSensor_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace project_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use project_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const project_interfaces::action::RequestSensor_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  project_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use project_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const project_interfaces::action::RequestSensor_GetResult_Response & msg)
{
  return project_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<project_interfaces::action::RequestSensor_GetResult_Response>()
{
  return "project_interfaces::action::RequestSensor_GetResult_Response";
}

template<>
inline const char * name<project_interfaces::action::RequestSensor_GetResult_Response>()
{
  return "project_interfaces/action/RequestSensor_GetResult_Response";
}

template<>
struct has_fixed_size<project_interfaces::action::RequestSensor_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<project_interfaces::action::RequestSensor_Result>::value> {};

template<>
struct has_bounded_size<project_interfaces::action::RequestSensor_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<project_interfaces::action::RequestSensor_Result>::value> {};

template<>
struct is_message<project_interfaces::action::RequestSensor_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<project_interfaces::action::RequestSensor_GetResult>()
{
  return "project_interfaces::action::RequestSensor_GetResult";
}

template<>
inline const char * name<project_interfaces::action::RequestSensor_GetResult>()
{
  return "project_interfaces/action/RequestSensor_GetResult";
}

template<>
struct has_fixed_size<project_interfaces::action::RequestSensor_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<project_interfaces::action::RequestSensor_GetResult_Request>::value &&
    has_fixed_size<project_interfaces::action::RequestSensor_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<project_interfaces::action::RequestSensor_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<project_interfaces::action::RequestSensor_GetResult_Request>::value &&
    has_bounded_size<project_interfaces::action::RequestSensor_GetResult_Response>::value
  >
{
};

template<>
struct is_service<project_interfaces::action::RequestSensor_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<project_interfaces::action::RequestSensor_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<project_interfaces::action::RequestSensor_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "project_interfaces/action/detail/request_sensor__traits.hpp"

namespace project_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const RequestSensor_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RequestSensor_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RequestSensor_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace project_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use project_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const project_interfaces::action::RequestSensor_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  project_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use project_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const project_interfaces::action::RequestSensor_FeedbackMessage & msg)
{
  return project_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<project_interfaces::action::RequestSensor_FeedbackMessage>()
{
  return "project_interfaces::action::RequestSensor_FeedbackMessage";
}

template<>
inline const char * name<project_interfaces::action::RequestSensor_FeedbackMessage>()
{
  return "project_interfaces/action/RequestSensor_FeedbackMessage";
}

template<>
struct has_fixed_size<project_interfaces::action::RequestSensor_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<project_interfaces::action::RequestSensor_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<project_interfaces::action::RequestSensor_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<project_interfaces::action::RequestSensor_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<project_interfaces::action::RequestSensor_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<project_interfaces::action::RequestSensor>
  : std::true_type
{
};

template<>
struct is_action_goal<project_interfaces::action::RequestSensor_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<project_interfaces::action::RequestSensor_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<project_interfaces::action::RequestSensor_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // PROJECT_INTERFACES__ACTION__DETAIL__REQUEST_SENSOR__TRAITS_HPP_
