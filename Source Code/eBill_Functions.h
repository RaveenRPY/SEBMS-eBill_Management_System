float Desired_Total_Bill;

int Switch1_stat = 0;
int Switch2_stat = 0;
int Bulb1_Stat = 1;
int Bulb2_Stat = 1;

void Bill_Genarator(int Monthly_Points) {

  //---------------- Under 60 kwh ----------------------

  if (Monthly_Points <= 60) {
    if (Monthly_Points <= 30) {
      Desired_Total_Bill = (Monthly_Points * 8.00) + 120;
    } else {
      Desired_Total_Bill = (30 * 8.00) + ((Monthly_Points - 30) * 10.00) + 240;
    }
  }

  //---------------- above 60 kwh ----------------------

  else {
    if (Monthly_Points <= 90) {
      Desired_Total_Bill = (60 * 16.00) + ((Monthly_Points - 60) * 16.00) + 360;
    } else if (Monthly_Points <= 120) {
      Desired_Total_Bill = (90 * 16.00) + ((Monthly_Points - 90) * 50.00) + 960;
    } else if (Monthly_Points <= 180) {
      Desired_Total_Bill = (90 * 16.00) + ((Monthly_Points - 90) * 50.00) + 960;
    } else {
      Desired_Total_Bill = (90 * 16.00) + (90 * 50.00) + ((Monthly_Points - 180) * 75.0) + 1500;
    }
  }
  //-------------------------------------------------------
}

void ManualControl(int Manual_Switch_1_Pin, int Manual_Switch_2_Pin, int Bulb_1_Pin, int Bulb_2_Pin) {

  int Switch1_Value = digitalRead(Manual_Switch_1_Pin);
  int Switch2_Value = digitalRead(Manual_Switch_2_Pin);

  Bulb1_Stat = digitalRead(Bulb_1_Pin);
  Bulb2_Stat = digitalRead(Bulb_2_Pin);

  if (Switch1_stat == Switch1_Value) {
    Switch1_stat = !Switch1_Value;
    Blynk.virtualWrite(V0, !Bulb1_Stat);
    digitalWrite(Bulb_1_Pin, !Bulb1_Stat);
    Bulb1_Stat = !Bulb1_Stat;
  }
  if (Switch2_stat == Switch2_Value) {
    Switch2_stat = !Switch2_Value;
    Blynk.virtualWrite(V1, !Bulb2_Stat);
    digitalWrite(Bulb_2_Pin, !Bulb2_Stat);
    Bulb2_Stat = !Bulb2_Stat;
  }
}