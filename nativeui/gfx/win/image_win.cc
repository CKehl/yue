// Copyright 2016 Cheng Zhao. All rights reserved.
// Use of this source code is governed by the license that can be found in the
// LICENSE file.

#include "nativeui/gfx/image.h"

#include "nativeui/gfx/win/gdiplus.h"

namespace nu {

Image::Image(const base::FilePath& path)
    : scale_factor_(GetScaleFactorFromFilePath(path)),
      image_(new Gdiplus::Image(path.value().c_str())) {
}

Image::~Image() {
  delete image_;
}

SizeF Image::GetSize() const {
  Gdiplus::Image* image = const_cast<Gdiplus::Image*>(image_);
  return ScaleSize(SizeF(image->GetWidth(), image->GetHeight()),
                   1.f / scale_factor_);
}

NativeImage Image::GetNative() const {
  return image_;
}

}  // namespace nu
