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


#ifndef liSHAPE3DCLASS
#define liSHAPE3DCLASS

#if  defined(_WIN32)
#include <itkWindows.h>
#endif

#include <itkFstream.h>
#include <itkRGBPixel.h>
#include <itkLightObject.h>
#include <itkObjectFactory.h>
#include <itkPoint.h>
#include <fltkGlDrawer.h>
#include <liCommandEvents.h>
#include <list>
#include <FL/gl.h>



namespace li {

/**
 *
 *  Shape3D is the base class for 3D graphical objects.
 *  This class have methods to define the appearance of
 *  the graphic object.
 *
 *  The class implements the Composite Pattern, so Shape3D
 *  can have sub-part and be composed hierarchicaly in more
 *  complex structures.
 * 
 */
class ITK_EXPORT Shape3D : public itk::LightObject, 
                  public fltk::GlDrawer {

public:
  /**
   * Standard "Self" typedef.
   */
  typedef Shape3D   Self;

  /**
   * Standard "Superclass" typedef.
   */
  typedef itk::LightObject  Superclass;

  /** 
   * Smart pointer typedef support.
   */
  typedef itk::SmartPointer<Self>  Pointer;

  /** 
   * ConstSmart pointer typedef support.
   */
  typedef itk::SmartPointer<const Self>  ConstPointer;

  /** 
   * Run-time type information (and related methods).
   */
  itkTypeMacro(Shape3D, LightObject);


  /** 
   * New macro
   */
  itkNewMacro(Self);


  /** 
   * Container used for Composite Pattern implementation
   */
  typedef std::list<Pointer>       ContainerType;


  /** 
   * Color Type
   */
  typedef itk::RGBPixel<GLfloat>        ColorType;

  /**
   * Type for points in 3D
   */
  typedef itk::Point< double, 3 >    PointType;


 /**
   * Type for vectors in 3D
   */
  typedef itk::Vector< double, 3 >    VectorType;
  

  /**
   *   Output stream type
   */ 
  typedef itk::Ofstream OfstreamType;


  /**
   *   Intput stream type
   */ 
  typedef itk::Ifstream IfstreamType;



  enum  drawingModes {
    none,
    points,
    lines,
    triangles,
    surfacepoints
    };

  enum  compileModes {
    noCompile,
    onlyCompile,
    compileExecute
    };

   
protected:
  /**
   * Constructor
   */
  Shape3D();

public:
  /**
   * Destructor
   */
  virtual ~Shape3D();

  /**
   * Sets the style for drawing: Triangles, Lines, Points...
   */
  virtual void SetDrawingMode(enum drawingModes newmode);

  /**
   * Defines if the commads will be compiled in
   * an OpenGL DisplayList or not
   */
  virtual void SetCompileMode(enum compileModes newmode);

  /**
   * Sets the color of the shape.
   * The color is propagated to all the components
   */
  virtual void SetColor(const ColorType &newcolor);

  /**
   * Sets the transparency of the shape.
   * The transparency is propagated to all the components
   */
  virtual void SetTransparency(GLfloat transparency);

  /**
   * Draw the geometrical aspect of the Shape.
   * This function must be overloaded by any descendent
   * class, in order to implement the OpenGL of its 
   * particular form
   */
  virtual void DrawGeometry(void) const;

  /**
   * Returns the transparency of the shape.
   */
  GLfloat GetTransparency(void) const { return m_Transparency; }

  /**
   * Returns the drawing mode 
   */
  drawingModes GetDrawingMode(void) const { return m_DrawingMode; }

  /**
   * Returns the OpenGL displayList compile mode 
   */
  compileModes GetCompileMode(void) const { return m_CompileMode; }

  /**
   * Returns the Color
   */
  const ColorType & GetColor(void) const { return m_Color; }

  /**
   * Send the color to OpenGL.
   * This is the color used when LIGHTING is disabled.
   * This function should only be called 
   * inside an OpenGL context.
   */
  void glColor(void) const;

  /**
   * Send the material color to OpenGL.
   * This is the color used when LIGHTING is enabled.
   * This function should only be called 
   * inside an OpenGL context.
   */
  void glMaterialColor(void) const;

  /**
   * Draws the figure with OpenGL commands.
   * This function should only be called 
   * inside an OpenGL context
   */
  void glDraw(void) const;


  /**
   * Returns the current position of the 
   * model in world coordinates
   */
  const PointType & GetCurrentPosition(void) const;


  /**
   * Returns the position of a point in Model space
   */
  PointType ComputeCurrentPosition(const PointType &) const;


  /**
   * Returns the current Orientation in Model space
   */
  VectorType ComputeCurrentOrientation(const VectorType & ) const;


  /**
   * Compute the transform that defines model's position
   * in world coordinates 
   */
  void ComputeCurrentTransform(void) const;


 
  /**
   * Invoke redrawing actions in the observers
   */
  void Redraw(void) const;


  /**
   * Invoke events recursively
   */
  void InvokeEvent( EventIds event ) const;

  
  /**
   * Set the selection for auto position in world coordinates
   */
  void SetAutoSensing( bool ) const;


  /**
   * Get the selection for auto position in world coordinates
   */
  bool GetAutoSensing( void ) const;


  /**
   * Select to restore the transform that defines the position
   * of the object in world coordinates before the next redraw
   */
  void SetRestoreTransform( bool ) const;


  /**
   * Schedule the display list to be modified in the next redraw
   */
  void ScheduleToUpdateDisplayList(void);

  /**
   * Schedule the display list to be removed in the next redraw
   */
  void RemoveDisplayList(void);
  
  /**
   * Adds another shape as components. 
   * This is part of the Composite Pattern behavior.
   */
  void AddComponent(  Shape3D * );

  /**
   * Removes one of the components. 
   * This is part of the Composite Pattern behavior.
   */
  void RemoveComponent( Shape3D * );

  /**
   * Get the first component of the component list. 
   * This is part of the Composite Pattern behavior.
   */
  ContainerType::iterator GetFirstComponent(void);

private:

  /**
   * Color to be used for drawing the Shape in OpenGL
   */
  ColorType           m_Color;

  /**
   * Transparency to be used for drawing the Shape in OpenGL
   */
  GLfloat             m_Transparency;

  /**
   * Array of component that implements the Composite Pattern
   */
  ContainerType       m_Components;

  /**
   * Pointer to a parent shape.
   * It allows to communicate with the Composite hierarchy.
   */
  Pointer             m_Father;

  /**
   * Mode used for drawing the Shape in OpenGL.
   * It could be triangles, lines, points...
   */
  enum drawingModes   m_DrawingMode;

  /**
   * Mode of compilation used by the DisplayList in OpenGL
   */
  enum compileModes   m_CompileMode;

  /**
   * Schedule the OpenGL DisplayList to be destroyed in 
   * the next redraw.
   */
  mutable   bool      m_ScheduledToRemoveDisplayList;

  /**
   * Schedule the display list to be updated in the next
   * redraw. This method should be called by any Set() 
   * method that modifies the appearance of the Shape.
   */
  mutable   bool      m_ScheduledToUpdateDisplayList;

  /**
   * Identification for the OpenGL display list assigned to
   * this shape. There could be conflicts when the same
   * shape is drawn in different OpenGL contexts.
   */
  mutable   GLint     m_DisplayList;


  /**
   * Define whether to compute or not the current transform that
   * defines the position of the object in world coordinates
   */
	mutable   bool   m_AutoSensing; 


  /**
   * Define whether to restore or not the current transform that
   * defines the position of the object in world coordinates
   */
	mutable   bool   m_RestoreTransform; 


  /**
   * Current transform that define the position of the Shape
   * in world coordinates
   */
  mutable GLfloat m_Transform[16];


  /**
   * Current position in space
   * in world coordinates
   */
  mutable PointType   m_CurrentPosition;



};

} // end namespace li


#endif
