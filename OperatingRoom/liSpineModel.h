/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    liSpineModel.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) 2002 Insight Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
//--------------------------------------------
//
//     Project: Operating Room
//
//     Author:  Luis Ibanez
//
//     Division of Neurosugery
//     Department of Surgery
//     University of North Carolina
//     Chapel Hill, NC 27599
//
//--------------------------------------------

#ifndef liSPINEMODELCLASS
#define liSPINEMODELCLASS

#include "liVertebralSegment.h"

namespace li {
/**  This class implements a 3D model of a set of vertebral segments */
class ITK_EXPORT SpineModel : public fltk::Shape3D
{
public:
  /** Standard class typedefs. */
  typedef SpineModel   Self;
  typedef fltk::Shape3D  Superclass;
  typedef itk::SmartPointer<Self>  Pointer;
  typedef itk::SmartPointer<const Self>  ConstPointer;

  /** Vertebra container  */
  typedef std::vector< VertebralSegment::Pointer >    VertebraContainer;

  /*** Run-time type information (and related methods). */
  itkTypeMacro( SpineModel, fltk::Shape3D );

  /** Method for creation through the object factory. */
  itkNewMacro( Self );

  /** Returns whether the spine contains vertebras or not */
  bool Null() const;

  /** Get Cranio Caudal Angle */
  double GetCranioCaudalAngle( void ) const;

  /** Get Rao Lao Angle */
  double GetRaoLaoAngle( void ) const;

  /** Get Axial Angle */
  double GetAxialAngle( void ) const;

  /** Get Vertebral Segments Iterator */
  VertebraContainer::iterator GetVertebralSegmentsBegin( void );

  /** Get Vertebral Segments Iterator */
  VertebraContainer::iterator GetVertebralSegmentsEnd( void );

  /** Get Position */
  const fltk::Shape3D::PointType & GetPosition( void ) const;

  /** Set Cranio Caudal Angle */
  void SetCranioCaudalAngle( double angle );

  /** Set Rao Lao Angle */
  void SetRaoLaoAngle( double angle );

  /** Set Axial Angle */
  void SetAxialAngle( double angle );

  /** Set Position */
  void SetPosition( const PointType & pnt );

protected:
 /** Constructor*/
  SpineModel();

  /** Destructor */
  ~SpineModel();

public:
  /**  Load from file */
  virtual void Load(const char *filename);

  /**  Save to a file */
  virtual void Save(const char *filename);

  /**  Save to a file */
  void DrawGeometry(void) const;
  
  /**  Write to an ofstream */
  int Write( fltk::Shape3D::OfstreamType &os,int level ) const;

  /**  Read from an ifstream */
  int Read( fltk::Shape3D::IfstreamType &is );

private:
  /**  STL vector containing a set of contiguous vertebral segments */
  VertebraContainer       m_Segments;

  /**  Rao Lao Angle */
  double                  m_RaoLaoAngle;

  /**  Cranio Caudal Angle */
  double                  m_CranioCaudalAngle;

  /**  Axial Angle */
  double                  m_AxialAngle;

  /**  Position */
  PointType               m_Position;
  
};

} // end namespace li



#endif




