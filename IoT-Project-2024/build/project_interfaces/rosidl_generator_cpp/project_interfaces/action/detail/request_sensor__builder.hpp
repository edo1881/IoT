// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from project_interfaces:action/RequestSensor.idl
// generated code does not contain a copyright notice

#ifndef PROJECT_INTERFACES__ACTION__DETAIL__REQUEST_SENSOR__BUILDER_HPP_
#define PROJECT_INTERFACES__ACTION__DETAIL__REQUEST_SENSOR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "project_interfaces/action/detail/request_sensor__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace project_interfaces
{

namespace action
{

namespace builder
{

class Init_RequestSensor_Goal_bs_request
{
public:
  Init_RequestSensor_Goal_bs_request()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::project_interfaces::action::RequestSensor_Goal bs_request(::project_interfaces::action::RequestSensor_Goal::_bs_request_type arg)
  {
    msg_.bs_request = std::move(arg);
    return std::move(msg_);
  }

private:
  ::project_interfaces::action::RequestSensor_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::project_interfaces::action::RequestSensor_Goal>()
{
  return project_interfaces::action::builder::Init_RequestSensor_Goal_bs_request();
}

}  // namespace project_interfaces


namespace project_interfaces
{

namespace action
{

namespace builder
{

class Init_RequestSensor_Result_balloons_response
{
public:
  Init_RequestSensor_Result_balloons_response()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::project_interfaces::action::RequestSensor_Result balloons_response(::project_interfaces::action::RequestSensor_Result::_balloons_response_type arg)
  {
    msg_.balloons_response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::project_interfaces::action::RequestSensor_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::project_interfaces::action::RequestSensor_Result>()
{
  return project_interfaces::action::builder::Init_RequestSensor_Result_balloons_response();
}

}  // namespace project_interfaces


namespace project_interfaces
{

namespace action
{

namespace builder
{

class Init_RequestSensor_Feedback_feed
{
public:
  Init_RequestSensor_Feedback_feed()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::project_interfaces::action::RequestSensor_Feedback feed(::project_interfaces::action::RequestSensor_Feedback::_feed_type arg)
  {
    msg_.feed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::project_interfaces::action::RequestSensor_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::project_interfaces::action::RequestSensor_Feedback>()
{
  return project_interfaces::action::builder::Init_RequestSensor_Feedback_feed();
}

}  // namespace project_interfaces


namespace project_interfaces
{

namespace action
{

namespace builder
{

class Init_RequestSensor_SendGoal_Request_goal
{
public:
  explicit Init_RequestSensor_SendGoal_Request_goal(::project_interfaces::action::RequestSensor_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::project_interfaces::action::RequestSensor_SendGoal_Request goal(::project_interfaces::action::RequestSensor_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::project_interfaces::action::RequestSensor_SendGoal_Request msg_;
};

class Init_RequestSensor_SendGoal_Request_goal_id
{
public:
  Init_RequestSensor_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RequestSensor_SendGoal_Request_goal goal_id(::project_interfaces::action::RequestSensor_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_RequestSensor_SendGoal_Request_goal(msg_);
  }

private:
  ::project_interfaces::action::RequestSensor_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::project_interfaces::action::RequestSensor_SendGoal_Request>()
{
  return project_interfaces::action::builder::Init_RequestSensor_SendGoal_Request_goal_id();
}

}  // namespace project_interfaces


namespace project_interfaces
{

namespace action
{

namespace builder
{

class Init_RequestSensor_SendGoal_Response_stamp
{
public:
  explicit Init_RequestSensor_SendGoal_Response_stamp(::project_interfaces::action::RequestSensor_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::project_interfaces::action::RequestSensor_SendGoal_Response stamp(::project_interfaces::action::RequestSensor_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::project_interfaces::action::RequestSensor_SendGoal_Response msg_;
};

class Init_RequestSensor_SendGoal_Response_accepted
{
public:
  Init_RequestSensor_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RequestSensor_SendGoal_Response_stamp accepted(::project_interfaces::action::RequestSensor_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_RequestSensor_SendGoal_Response_stamp(msg_);
  }

private:
  ::project_interfaces::action::RequestSensor_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::project_interfaces::action::RequestSensor_SendGoal_Response>()
{
  return project_interfaces::action::builder::Init_RequestSensor_SendGoal_Response_accepted();
}

}  // namespace project_interfaces


namespace project_interfaces
{

namespace action
{

namespace builder
{

class Init_RequestSensor_GetResult_Request_goal_id
{
public:
  Init_RequestSensor_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::project_interfaces::action::RequestSensor_GetResult_Request goal_id(::project_interfaces::action::RequestSensor_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::project_interfaces::action::RequestSensor_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::project_interfaces::action::RequestSensor_GetResult_Request>()
{
  return project_interfaces::action::builder::Init_RequestSensor_GetResult_Request_goal_id();
}

}  // namespace project_interfaces


namespace project_interfaces
{

namespace action
{

namespace builder
{

class Init_RequestSensor_GetResult_Response_result
{
public:
  explicit Init_RequestSensor_GetResult_Response_result(::project_interfaces::action::RequestSensor_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::project_interfaces::action::RequestSensor_GetResult_Response result(::project_interfaces::action::RequestSensor_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::project_interfaces::action::RequestSensor_GetResult_Response msg_;
};

class Init_RequestSensor_GetResult_Response_status
{
public:
  Init_RequestSensor_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RequestSensor_GetResult_Response_result status(::project_interfaces::action::RequestSensor_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_RequestSensor_GetResult_Response_result(msg_);
  }

private:
  ::project_interfaces::action::RequestSensor_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::project_interfaces::action::RequestSensor_GetResult_Response>()
{
  return project_interfaces::action::builder::Init_RequestSensor_GetResult_Response_status();
}

}  // namespace project_interfaces


namespace project_interfaces
{

namespace action
{

namespace builder
{

class Init_RequestSensor_FeedbackMessage_feedback
{
public:
  explicit Init_RequestSensor_FeedbackMessage_feedback(::project_interfaces::action::RequestSensor_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::project_interfaces::action::RequestSensor_FeedbackMessage feedback(::project_interfaces::action::RequestSensor_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::project_interfaces::action::RequestSensor_FeedbackMessage msg_;
};

class Init_RequestSensor_FeedbackMessage_goal_id
{
public:
  Init_RequestSensor_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RequestSensor_FeedbackMessage_feedback goal_id(::project_interfaces::action::RequestSensor_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_RequestSensor_FeedbackMessage_feedback(msg_);
  }

private:
  ::project_interfaces::action::RequestSensor_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::project_interfaces::action::RequestSensor_FeedbackMessage>()
{
  return project_interfaces::action::builder::Init_RequestSensor_FeedbackMessage_goal_id();
}

}  // namespace project_interfaces

#endif  // PROJECT_INTERFACES__ACTION__DETAIL__REQUEST_SENSOR__BUILDER_HPP_
