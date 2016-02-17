#ifndef SIMULATOR_PANEL_H
#define SIMULATOR_PANEL_H

#include <stdio.h>
#include <boost/lexical_cast.hpp>

#include <ros/ros.h>
#include <rviz/panel.h>
#include <mtracker/Trigger.h>

#include <QCheckBox>
#include <QVBoxLayout>

namespace mtracker_gui
{

class SimulatorPanel : public rviz::Panel
{
Q_OBJECT
public:
  SimulatorPanel(QWidget* parent = 0);

  virtual void load(const rviz::Config& config);
  virtual void save(rviz::Config config) const;

private Q_SLOTS:
  void callTrigger(bool checked);

private:
  QCheckBox* activate_checkbox_;

  ros::NodeHandle nh_;
  ros::ServiceClient trigger_cli_;
};

} // end namespace mtracker_gui

#endif // SIMULATOR_PANEL_H