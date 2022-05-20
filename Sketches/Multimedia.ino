//Данный скетч имеет 4 комбинации: Pause/Play, Vol_Up, Vol_Down, Next_Track.
//This sketch contains 4 combitations: Pause/Play, Vol_Up, Vol_Down, Next_Track.
#include <TrinketHidCombo.h>
void setup() {
  // put your setup code here, to run once:
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);

  TrinketHidCombo.begin();
}

bool ctrlKey = 0;
bool ctrlLastKey = 0;

bool winKey = 0;
bool winLastKey = 0;

bool cKey = 0;
bool cLastKey = 0;

bool vKey = 0;
bool vLastKey = 0;

void loop() {
  TrinketHidCombo.poll();
  // put your main code here, to run repeatedly:
  //считываем текущее значение
  ctrlKey = !digitalRead(0);
  // при нажатии кнопки
  if (ctrlKey && !ctrlLastKey)
  {
    ctrlLastKey = ctrlKey;
    TrinketHidCombo.pressMultimediaKey(MMKEY_PLAYPAUSE);
  }
  // при отпускании кнопки
  if (!ctrlKey && ctrlLastKey)
  {
    ctrlLastKey = ctrlKey;
    TrinketHidCombo.pressMultimediaKey(0);
  }

    //считываем текущее значение
  winKey = digitalRead(1);
  // при нажатии кнопки
  if (!winKey && winLastKey)
  {
    winLastKey = winKey;
    TrinketHidCombo.pressMultimediaKey(MMKEY_VOL_UP);
  }
  // при отпускании кнопки
  if (winKey && !winLastKey)
  {
    winLastKey = winKey;
    TrinketHidCombo.pressMultimediaKey(0);
  }

    //считываем текущее значение
  cKey = !digitalRead(2);
  // при нажатии кнопки
  if (cKey && !cLastKey)
  {
    cLastKey = cKey;
    TrinketHidCombo.pressMultimediaKey(MMKEY_VOL_DOWN);
  }
  // при отпускании кнопки
  if (!cKey && cLastKey)
  {
    cLastKey = cKey;
    TrinketHidCombo.pressMultimediaKey(0);
  }

    //считываем текущее значение
  vKey = !digitalRead(5);
  // при нажатии кнопки
  if (vKey && !vLastKey)
  {
    vLastKey = vKey;
    TrinketHidCombo.pressMultimediaKey(MMKEY_SCAN_NEXT_TRACK);
    delay(50);
  }
  // при отпускании кнопки
  if (!vKey && vLastKey)
  {
    vLastKey = vKey;
    TrinketHidCombo.pressMultimediaKey(0);
    delay(50);
  }
  TrinketHidCombo.poll();
}
