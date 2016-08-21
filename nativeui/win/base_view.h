// Copyright 2016 Cheng Zhao. All rights reserved.
// Use of this source code is governed by the license that can be found in the
// LICENSE file.

#ifndef NATIVEUI_WIN_BASE_VIEW_H_
#define NATIVEUI_WIN_BASE_VIEW_H_

#include <windows.h>

#include "base/macros.h"
#include "ui/gfx/geometry/rect.h"

namespace nu {

// The common base for native window based view and directui view.
class BaseView {
 public:
  virtual ~BaseView() {}

  virtual void SetPixelBounds(const gfx::Rect& pixel_bounds) = 0;
  virtual gfx::Rect GetPixelBounds() = 0;

  virtual void SetParent(BaseView* parent) {
    parent_ = parent;
  }

  void SetBounds(const gfx::Rect& bounds);
  gfx::Rect GetBounds();

  HWND hwnd() const { return hwnd_; }
  bool is_virtual() const { return is_virtual_; }
  float scale_factor() const { return scale_factor_; }
  BaseView* parent() const { return parent_; }

 protected:
  explicit BaseView(bool is_virtual) : is_virtual_(is_virtual) {}

  void Init(HWND hwnd, float scale_factor);

 private:
  bool is_virtual_;

  // The parent BaseView.
  BaseView* parent_ = nullptr;

  // The native holder of this view.
  HWND hwnd_ = NULL;

  // The scale factor of current window.
  // TODO(zcbenz): Refresh the window when DPI changes.
  float scale_factor_ = 1.0f;

  DISALLOW_COPY_AND_ASSIGN(BaseView);
};

}  // namespace nu

#endif  // NATIVEUI_WIN_BASE_VIEW_H_
