// generated by Fast Light User Interface Designer (fluid) version 1.0011

#ifndef fltkRegularStepGradientDescentGUI_h
#define fltkRegularStepGradientDescentGUI_h
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Counter.H>
#include <FL/Fl_Button.H>

class RegularStepGradientDescentGUI {
public:
  RegularStepGradientDescentGUI();
  Fl_Window *controlPanel;
  Fl_Value_Input *minimumStepLengthValuator;
private:
  inline void cb_minimumStepLengthValuator_i(Fl_Value_Input*, void*);
  static void cb_minimumStepLengthValuator(Fl_Value_Input*, void*);
public:
  Fl_Value_Input *maximumStepLengthValuator;
private:
  inline void cb_maximumStepLengthValuator_i(Fl_Value_Input*, void*);
  static void cb_maximumStepLengthValuator(Fl_Value_Input*, void*);
public:
  Fl_Value_Input *gradientMagnitudeToleranceValuator;
private:
  inline void cb_gradientMagnitudeToleranceValuator_i(Fl_Value_Input*, void*);
  static void cb_gradientMagnitudeToleranceValuator(Fl_Value_Input*, void*);
public:
  Fl_Counter *maximumNumberOfIterationsCounter;
private:
  inline void cb_maximumNumberOfIterationsCounter_i(Fl_Counter*, void*);
  static void cb_maximumNumberOfIterationsCounter(Fl_Counter*, void*);
  inline void cb_Start_i(Fl_Button*, void*);
  static void cb_Start(Fl_Button*, void*);
  inline void cb_Stop_i(Fl_Button*, void*);
  static void cb_Stop(Fl_Button*, void*);
  inline void cb_Resume_i(Fl_Button*, void*);
  static void cb_Resume(Fl_Button*, void*);
  inline void cb_Close_i(Fl_Button*, void*);
  static void cb_Close(Fl_Button*, void*);
public:
  virtual ~RegularStepGradientDescentGUI();
  virtual void SetMaximumStepLength( double );
  virtual void SetMinimumStepLength( double );
  virtual void SetGradientMagnitudeTolerance( double );
  virtual void SetMaximumNumberOfIterations( double );
  virtual void StartOptimization(void);
  virtual void StopOptimization(void);
  virtual void ResumeOptimization(void);
  virtual void Hide(void);
  virtual void Show(void);
};
#endif
