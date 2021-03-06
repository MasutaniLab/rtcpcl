/* RTM:PCL Point Cloud Type
 *
 * Traits for PCL point types.
 *
 * Copyright 2011 Geoffrey Biggs geoffrey.biggs@aist.go.jp
 *     RT-Synthesis Research Group
 *     Intelligent Systems Research Institute,
 *     National Institute of Advanced Industrial Science and Technology (AIST),
 *     Japan
 *     All rights reserved.
 *
 * This file is part of RTM:PCL.
 *
 * RTM:PCL is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 2.1 of the License,
 * or (at your option) any later version.
 *
 * RTM:PCL is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with RTM:PCL. If not, see
 * <http://www.gnu.org/licenses/>.
 */

#if !defined(PC_TRAITS_H_)
#define PC_TRAITS_H_


#include <boost/algorithm/string.hpp>
#include <boost/any.hpp>
#include <pcl/point_types.h>
#include <stdexcept>

#ifdef _EXPORTING
  #define CLASS_DECLSPEC __declspec(dllexport)
#else
  #define CLASS_DECLSPEC __declspec(dllimport)
#endif

namespace RTCPCL
{
    // Trait for any PCL point type
    template<typename PointT>
    struct CLASS_DECLSPEC AnyPoint
    {
        static bool const value = true;
    };


    // Trait for points with XYZ fields
    template<typename PointT>
    struct CLASS_DECLSPEC HasXYZ
    {
        static bool const value = false;
    };

    template<>
    struct CLASS_DECLSPEC HasXYZ<pcl::PointXYZ>
    {
        static bool const value = true;
    };

    template<>
    struct CLASS_DECLSPEC HasXYZ<pcl::PointXYZI>
    {
        static bool const value = true;
    };

    template<>
    struct CLASS_DECLSPEC HasXYZ<pcl::PointXYZRGBA>
    {
        static bool const value = true;
    };

    template<>
    struct CLASS_DECLSPEC HasXYZ<pcl::PointXYZRGB>
    {
        static bool const value = true;
    };

    template<>
    struct CLASS_DECLSPEC HasXYZ<pcl::InterestPoint>
    {
        static bool const value = true;
    };

    template<>
    struct CLASS_DECLSPEC HasXYZ<pcl::PointNormal>
    {
        static bool const value = true;
    };

    template<>
    struct CLASS_DECLSPEC HasXYZ<pcl::PointXYZRGBNormal>
    {
        static bool const value = true;
    };

    template<>
    struct CLASS_DECLSPEC HasXYZ<pcl::PointXYZINormal>
    {
        static bool const value = true;
    };

    template<>
    struct CLASS_DECLSPEC HasXYZ<pcl::PointWithRange>
    {
        static bool const value = true;
    };

    template<>
    struct CLASS_DECLSPEC HasXYZ<pcl::PointWithViewpoint>
    {
        static bool const value = true;
    };

    template<>
    struct CLASS_DECLSPEC HasXYZ<pcl::PointWithScale>
    {
        static bool const value = true;
    };


    // Trait for points with RGB fields
    template<typename PointT>
    struct CLASS_DECLSPEC HasRGB
    {
        static bool const value = false;
    };

    /*template<>
    struct CLASS_DECLSPEC HasRGB<pcl::PointXYZRGBA>
    {
        static bool const value = true;
    };*/

    template<>
    struct CLASS_DECLSPEC HasRGB<pcl::PointXYZRGB>
    {
        static bool const value = true;
    };

    template<>
    struct CLASS_DECLSPEC HasRGB<pcl::PointXYZRGBNormal>
    {
        static bool const value = true;
    };


    // Trait for points with a Normal field
    template<typename PointT>
    struct CLASS_DECLSPEC HasNormals
    {
        static bool const value = false;
    };

    template<>
    struct CLASS_DECLSPEC HasNormals<pcl::Normal>
    {
        static bool const value = true;
    };

    template<>
    struct CLASS_DECLSPEC HasNormals<pcl::PointNormal>
    {
        static bool const value = true;
    };

    template<>
    struct CLASS_DECLSPEC HasNormals<pcl::PointXYZRGBNormal>
    {
        static bool const value = true;
    };

    template<>
    struct CLASS_DECLSPEC HasNormals<pcl::PointXYZINormal>
    {
        static bool const value = true;
    };


    // Traits for points with curvature fields
    template<typename PointT>
    struct CLASS_DECLSPEC HasCurvatures
    {
        static bool const value = false;
    };

    template<>
    struct CLASS_DECLSPEC HasCurvatures<pcl::PrincipalCurvatures>
    {
        static bool const value = true;
    };


    // Traits for point names
    template<typename PointT>
    struct CLASS_DECLSPEC PointName
    {
        static std::string value;
    };

    template<>
    struct CLASS_DECLSPEC PointName<pcl::PointXYZ>
    {
        static std::string value; // xyz
    };

    template<>
    struct CLASS_DECLSPEC PointName<pcl::PointXYZI>
    {
        static std::string value; // xyzi
    };

    template<>
    struct CLASS_DECLSPEC PointName<pcl::PointXYZRGBA>
    {
        static std::string value; // xyzrgba
    };

    template<>
    struct CLASS_DECLSPEC PointName<pcl::PointXYZRGB>
    {
        static std::string value; // xyzrgb
    };

    template<>
    struct CLASS_DECLSPEC PointName<pcl::PointXY>
    {
        static std::string value; // xy
    };

    template<>
    struct CLASS_DECLSPEC PointName<pcl::InterestPoint>
    {
        static std::string value; // interestpoint
    };

    template<>
    struct CLASS_DECLSPEC PointName<pcl::Normal>
    {
        static std::string value; // normal
    };

    template<>
    struct CLASS_DECLSPEC PointName<pcl::PointNormal>
    {
        static std::string value; // normal
    };

    template<>
    struct CLASS_DECLSPEC PointName<pcl::PointXYZRGBNormal>
    {
        static std::string value; // xyzrgbnormal
    };

    template<>
    struct CLASS_DECLSPEC PointName<pcl::PointXYZINormal>
    {
        static std::string value; // xyzinormal
    };

    template<>
    struct CLASS_DECLSPEC PointName<pcl::PointWithRange>
    {
        static std::string value; // pointwithrange
    };

    template<>
    struct CLASS_DECLSPEC PointName<pcl::PointWithViewpoint>
    {
        static std::string value; // pointwithviewpoint
    };

    template<>
    struct CLASS_DECLSPEC PointName<pcl::MomentInvariants>
    {
        static std::string value; // momentinvariants
    };

    template<>
    struct CLASS_DECLSPEC PointName<pcl::PrincipalRadiiRSD>
    {
        static std::string value; // principalradiirsd
    };

    template<>
    struct CLASS_DECLSPEC PointName<pcl::Boundary>
    {
        static std::string value; // boundary
    };

    template<>
    struct CLASS_DECLSPEC PointName<pcl::PrincipalCurvatures>
    {
        static std::string value; // principalcurvatures
    };

    template<>
    struct CLASS_DECLSPEC PointName<pcl::PFHSignature125>
    {
        static std::string value; // pfhsignature125
    };

    /*template<>
    struct CLASS_DECLSPEC PointName<pcl::PPFSignature>
    {
        static std::string value; // ppfsignature
    };*/

    template<>
    struct CLASS_DECLSPEC PointName<pcl::FPFHSignature33>
    {
        static std::string value; // fpfhsignature33
    };

    template<>
    struct CLASS_DECLSPEC PointName<pcl::VFHSignature308>
    {
        static std::string value; // vfhsignature308
    };

    template<>
    struct CLASS_DECLSPEC PointName<pcl::Narf36>
    {
        static std::string value; // narf36
    };

    template<>
    struct CLASS_DECLSPEC PointName<pcl::IntensityGradient>
    {
        static std::string value; // intensitygradient
    };

    template<>
    struct CLASS_DECLSPEC PointName<pcl::PointWithScale>
    {
        static std::string value; // pointwithscale
    };

    template<>
    struct CLASS_DECLSPEC PointName<pcl::PointSurfel>
    {
        static std::string value; // pointsurfel
    };


#define PCL_TAGGED_POINT_TYPES ((xyz,pcl::PointXYZ)) \
        ((xyzi,pcl::PointXYZI)) \
        ((xyzrgba,pcl::PointXYZRGBA)) \
        ((xyzrgb,pcl::PointXYZRGB)) \
        ((interest,pcl::InterestPoint)) \
        ((normal,pcl::Normal)) \
        ((xyznormal,pcl::PointNormal)) \
        ((xyzrgbnormal,pcl::PointXYZRGBNormal)) \
        ((xyzinormal,pcl::PointXYZINormal)) \
        ((xyzrange,pcl::PointWithRange)) \
        ((xyzviewpoint,pcl::PointWithViewpoint)) \
        ((momentinvariants,pcl::MomentInvariants)) \
        ((pricipalradiirsd,pcl::PrincipalRadiiRSD)) \
        ((boundary,pcl::Boundary)) \
        ((principalcurvatures,pcl::PrincipalCurvatures)) \
        ((pfhsig125,pcl::PFHSignature125)) \
        ((fpfhsig33,pcl::FPFHSignature33)) \
        ((vfhsig308,pcl::VFHSignature308)) \
        ((narf36,pcl::Narf36)) \
        ((intensitygradient,pcl::IntensityGradient)) \
        ((pointwithscale,pcl::PointWithScale)) \
        ((pointsurfel,pcl::PointSurfel))
    /***/
        //((xy,pcl::PointXY))
        //((ppfsig,pcl::PPFSignature))


#define RTCPCL_MAKE_TEMPLATED_PCL_TYPE(r, _, elem) \
    if (point_type == BOOST_PP_STRINGIZE(BOOST_PP_TUPLE_ELEM(2, 0, elem))) \
    { \
        return create_type_impl<Traits<BOOST_PP_TUPLE_ELEM(2, 1, elem)>::value>:: \
            template do_it<TargetType<BOOST_PP_TUPLE_ELEM(2, 1, elem)> >(point_type); \
    }
    /***/


    template<bool b>
    struct CLASS_DECLSPEC create_type_impl
    {
        template<typename TargetType>
        static boost::any do_it(std::string const& point_type)
        {
            std::cerr << "Incompatible point type: " << point_type << '\n';
            throw std::runtime_error("Incompatible point type: " + point_type);
            return boost::any();
        }
    };

    template<>
    struct CLASS_DECLSPEC create_type_impl<true>
    {
        template<typename TargetType>
        static boost::any do_it(std::string const& point_type)
        {
            boost::any res;
            res = boost::shared_ptr<TargetType>(new TargetType);
            return res;
        }
    };

    /// Creates a type based on the point type specified in a string.
    ///
    /// Specify the type to create as the template parameter.
    /// @param point_type The point type. Must be a valid PCL point type. For
    /// example, "xyz" or "xyzrgb". Case insensitive.
    /// @return A new instance of the specified type, templated on the point
    /// type. The result is returned as a boost::shared_ptr to the instance
    /// stored in a boost::any object.
    template<template<typename>class TargetType,
        template<typename>class Traits>
    boost::any create_type(std::string point_type)
    {
        boost::to_lower(point_type);
        BOOST_PP_SEQ_FOR_EACH(RTCPCL_MAKE_TEMPLATED_PCL_TYPE, _,
                PCL_TAGGED_POINT_TYPES);
        throw std::runtime_error("Unknown point type: " + point_type);
    }
}; // namespace RTCPCL

#endif // !define(PC_TRAITS_H_

