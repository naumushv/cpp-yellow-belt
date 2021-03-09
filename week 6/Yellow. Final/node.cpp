#include "node.h"

bool EmptyNode::Evaluate(const Date &date, const std::string &event) {
  return true;
}

DateComparisonNode::DateComparisonNode(Comparison cmp, const Date &date)
    : cmp_(cmp), date_(date) {}

bool DateComparisonNode::Evaluate(const Date &date, const std::string &event) {
  Date d;
  if (date.GetDate() == d.GetDate()) {
    return false;
  }
  return Compare(cmp_, date, date_);
}

EventComparisonNode::EventComparisonNode(Comparison cmp, const std::string &event)
    : cmp_(cmp), event_(event) {}

bool EventComparisonNode::Evaluate(const Date &date, const std::string &event) {
  if (event.empty()) {
    return false;
  }
  return Compare(cmp_, event, event_);
}

LogicalOperationNode::LogicalOperationNode(LogicalOperation lo,
                                           std::shared_ptr<Node> left,
                                           std::shared_ptr<Node> right)
    : operation_(lo), left_(std::move(left)), right_(std::move(right)) {}

bool LogicalOperationNode::Evaluate(const Date &date, const std::string &event) {
  if (operation_ == LogicalOperation::And) {
    return left_->Evaluate(date, event) && right_->Evaluate(date, event);
  }
  else if (operation_ == LogicalOperation::Or) {
    return left_->Evaluate(date, event) || right_->Evaluate(date, event);
  }
  else {
    return false;
  }
}


