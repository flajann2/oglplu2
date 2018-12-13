/**
 *  @file eagine/unit/base_scaled_unit.hpp
 *
 */

#ifndef EAGINE_UNITS_BASE_SCALED_UNIT_1512222148_HPP
#define EAGINE_UNITS_BASE_SCALED_UNIT_1512222148_HPP

#include "base_unit.hpp"

namespace eagine {
namespace units {
namespace base {

template <typename Scale, typename Unit>
struct scaled_unit {
    using dimension = dimension_of_t<Unit>;
    using scale = Scale;
    using type = scaled_unit;
};

} // namespace base
} // namespace units
} // namespace eagine

#endif // include guard
