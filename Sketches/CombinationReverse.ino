#include <TrinketHidCombo.h>
void setup() {
  // put your setup code here, to run once:
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);

  TrinketHidCombo.begin();
}

char modKey = 0;
char Key = 0;

char modKeyCombo = 0;
char KeyCombo = 0;

bool ctrlKey = 0;
bool ctrlLastKey = 0;

bool winKey = 0;
bool winLastKey = 0;

bool cKey = 0;
bool cLastKey = 0;

bool vKey = 0;
bool vLastKey = 0;

void loop() {
  //считываем текущее значение
  ctrlKey = !digitalRead(0);
  // при нажатии кнопки
  if (ctrlKey && !ctrlLastKey)
  {
    ctrlLastKey = ctrlKey;
    modKey = KEYCODE_MOD_LEFT_CONTROL;
    Key = KEYCODE_A;
  }
  // при отпускании кнопки
  if (!ctrlKey && ctrlLastKey)
  {
    ctrlLastKey = ctrlKey;
    modKey = 0;
    Key = 0;
  }

    //считываем текущее значение
  winKey = digitalRead(1);
  // при нажатии кнопки
  if (!winKey && winLastKey)
  {
    winLastKey = winKey;
    modKey = KEYCODE_MOD_LEFT_CONTROL;
    Key = KEYCODE_V;
    KeyCombo = KEYCODE_V;
  }
  // при отпускании кнопки
  if (winKey && !winLastKey)
  {
    winLastKey = winKey;
    modKey = 0;
    Key = 0;
    modKeyCombo = 0;
  }

    //считываем текущее значение
  cKey = !digitalRead(2);
  // при нажатии кнопки
  if (cKey && !cLastKey)
  {
    cLastKey = cKey;
    modKey = KEYCODE_MOD_LEFT_CONTROL;
    Key = KEYCODE_C;
    modKeyCombo = KEYCODE_MOD_LEFT_GUI;
  }
  // при отпускании кнопки
  if (!cKey && cLastKey)
  {
    cLastKey = cKey;
    modKey = 0;
    Key = 0;
    KeyCombo = 0;
  }

    //считываем текущее значение
  vKey = !digitalRead(5);
  // при нажатии кнопки
  if (vKey && !vLastKey)
  {
    vLastKey = vKey;
    modKey = KEYCODE_MOD_LEFT_CONTROL;
    Key = KEYCODE_Z;
  }
  // при отпускании кнопки
  if (!vKey && vLastKey)
  {
    vLastKey = vKey;
    modKey = 0;
    Key = 0;
  }

  if ((modKeyCombo != 0) and (KeyCombo != 0)){
    TrinketHidCombo.pressKey(modKeyCombo, KeyCombo);
  }
  else{
    TrinketHidCombo.pressKey(modKey, Key);
  }
}
