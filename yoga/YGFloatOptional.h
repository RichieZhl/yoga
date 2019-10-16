/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the LICENSE
 * file in the root directory of this source tree.
 */
#pragma once

#include <cmath>
#include <limits>
#include "Yoga-internal.h"

struct YGFloatOptional {
private:
    float value_ = std::numeric_limits<float>::quiet_NaN();
    bool isUndefined_ = false;
    
public:
    explicit constexpr YGFloatOptional(float value) : value_(value) {}
    constexpr YGFloatOptional() = default;
    
    float getValue() const;
    
    // returns the wrapped value, or a value x with YGIsUndefined(x) == true
    constexpr float unwrap() const { return value_; }
    
    bool isUndefined() const { return std::isnan(value_); }
    
    bool operator==(const YGFloatOptional& op) const;
    bool operator!=(const YGFloatOptional& op) const;
    
    bool operator==(float val) const;
    
    bool operator!=(float val) const;
    
    YGFloatOptional operator+(const YGFloatOptional& op);
    
    bool operator>(const YGFloatOptional& op) const;
    
    bool operator<(const YGFloatOptional& op) const;
    
    bool operator>=(const YGFloatOptional& op) const;
    
    bool operator<=(const YGFloatOptional& op) const;
};

// operators take YGFloatOptional by value, as it is a 32bit value

//inline bool operator==(YGFloatOptional lhs, YGFloatOptional rhs) {
//  return lhs.unwrap() == rhs.unwrap() ||
//      (lhs.isUndefined() && rhs.isUndefined());
//}
inline bool operator!=(YGFloatOptional lhs, YGFloatOptional rhs) {
    return !(lhs == rhs);
}
//
//inline bool operator==(YGFloatOptional lhs, float rhs) {
//    return lhs == YGFloatOptional{rhs};
//}
//inline bool operator!=(YGFloatOptional lhs, float rhs) {
//    return !(lhs == rhs);
//}
//
//inline bool operator==(float lhs, YGFloatOptional rhs) {
//    return rhs.unwrap() == lhs;
//}
//inline bool operator!=(float lhs, YGFloatOptional rhs) {
//    return !(lhs == rhs);
//}
//
//inline YGFloatOptional operator+(YGFloatOptional lhs, YGFloatOptional rhs) {
//    return YGFloatOptional{lhs.unwrap() + rhs.unwrap()};
//}
//
//inline bool operator>(YGFloatOptional lhs, YGFloatOptional rhs) {
//    return lhs.unwrap() > rhs.unwrap();
//}
//
//inline bool operator<(YGFloatOptional lhs, YGFloatOptional rhs) {
//    return lhs.unwrap() < rhs.unwrap();
//}
//
//inline bool operator>=(YGFloatOptional lhs, YGFloatOptional rhs) {
//    return lhs > rhs || lhs == rhs;
//}
//
//inline bool operator<=(YGFloatOptional lhs, YGFloatOptional rhs) {
//    return lhs < rhs || lhs == rhs;
//}
