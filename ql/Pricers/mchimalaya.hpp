

/*
 Copyright (C) 2000, 2001, 2002, 2003 RiskMap srl

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it under the
 terms of the QuantLib license.  You should have received a copy of the
 license along with this program; if not, please email ferdinando@ametrano.net
 The license is also available online at http://quantlib.org/html/license.html

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

// $Id$

#ifndef quantlib_himalaya_h
#define quantlib_himalaya_h

#include <ql/Pricers/mcpricer.hpp>
#include <ql/Math/matrix.hpp>

namespace QuantLib {

    namespace Pricers {

        //! Himalayan-type option pricer
        /*! The payoff of a Himalaya option is computed in the following way:
            Given a basket of N assets, and N time periods, at end of
            each period the option who performed the best is added to the
            average and then discarded from the basket. At the end of the
            N periods the option pays the max between the strike and the
            average of the best performers.
        */
        class McHimalaya : public McPricer<Math::Statistics,
            MonteCarlo::GaussianMultiPathGenerator,
            MonteCarlo::PathPricer<MonteCarlo::MultiPath> > {
        public:
            McHimalaya(const Array& underlying,
                       const Array& dividendYield,
                       const Math::Matrix& covariance,
                       Rate riskFreeRate,
                       double strike,
                       const std::vector<Time>& times,
                       bool antitheticVariance,
                       long seed = 0);
        };

    }

}


#endif
