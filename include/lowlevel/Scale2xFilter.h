/*
 * Copyright (C) 2006-2014 Christopho, Solarus - http://www.solarus-games.org
 *
 * Solarus is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Solarus is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SOLARUS_SCALE2X_FILTER_H
#define SOLARUS_SCALE2X_FILTER_H

#include "Common.h"
#include "lowlevel/PixelFilter.h"

namespace solarus {

/**
 * \brief Implementation of the Scale2x algorithm.
 *
 * See http://scale2x.sourceforge.net/algorithm.html
 */
class Scale2xFilter: public PixelFilter {

  public:

    Scale2xFilter();
    ~Scale2xFilter();

    int get_scaling_factor() const;
    void filter(
        const uint32_t* src,
        int src_width,
        int src_height,
        uint32_t* dst) const;
};

}

#endif

