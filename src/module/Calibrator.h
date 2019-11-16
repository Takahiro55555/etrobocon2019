/**
 *  @file   Calibrator.h
 *  @brief  キャリブレーションを行うクラス
 *  @author korosuke613
 **/
#ifndef CALIBRATOR_H
#define CALIBRATOR_H

#include <cstring>
#include "Controller.h"
#include "Display.h"

enum class Brightness { WHITE, BLACK };

class Calibrator {
 public:
  explicit Calibrator(Controller& controller_);

  /** キャリブレーションを行う。
   * @brief
   * falseが返ってきた場合、エラーメッセージがLCDに出ます。スタートを取りやめ、原因をさぐってください。
   * @return キャリブレーションが成功したかどうかの真理値(Trueなら正常終了)
   */
  bool calibration();

  /** カメラシステムを使用するかどうかを判断する。
   * @return Lカメラシステムを使用するかどうかの真偽値（Trueなら使用する）
   */
  bool getCameraMode() const;

  /** Leftコースであるかどうかを判断する。
   * @return Leftコースであるかどうかの真偽値（TrueならLeftコース）
   */
  bool isLeftCourse() const;

  /** カメラシステムを使用するかどうかを設定する
   * @return 正常終了したかどうかの真偽値(Trueなら正常終了)
   */
  bool setCameraMode();

  /** LコースかRコースかを設定する。
   * @return 正常終了したかどうかの真偽値（Trueなら正常終了）
   */
  bool setLRCourse();

  /** 明るさを設定する。
   * @param brightness 白か黒かの明るさ
   * @return 正常終了したかどうかの真偽値（Trueなら正常終了）
   */
  bool setBrightness(Brightness brightness);

  /** アーム位置の自動調整 */
  void setArm();

  /** ディスプレイに表示されているものを消す */
  void deleteDisplayedText(int startTarget = 1,int endTarget = 11);

private:
  Controller& controller;
  bool isCameraMode;  // カメラシステムを使用するかどうか(Trueなら使用する)
  bool isLeft;        // Leftコースであるかどうかの真偽値（TrueならLeftコース）
};

#endif
