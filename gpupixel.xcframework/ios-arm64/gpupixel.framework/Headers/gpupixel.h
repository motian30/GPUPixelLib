
/*
 * GPUPixel
 *
 * Created by PixPark on 2021/6/24.
 * Copyright © 2021 PixPark. All rights reserved.
 */

#pragma once

#include "gpupixel_macros.h"

// base
#include "framebuffer.h"
#include "framebuffer_cache.h"
#include "gl_program.h"
#include "gpupixel_context.h"

// utils
#include "math_toolbox.h"
#include "util.h"

// source
#include "source.h"
#include "source_camera.h"
#include "source_image.h"
#include "source_raw_data.h"

// sink
#include "sink.h"
#include "sink_raw_data.h"
#include "sink_render.h"
#if defined(GPUPIXEL_IOS) || defined(GPUPIXEL_MAC)
#include "gpupixel_sink.h"
#include "gpupixel_view.h"
#include "objc_sink.h"
#endif

// base filters
#include "filter.h"
#include "filter_group.h"

// face filters
#include "beauty_face_filter.h"
#include "face_makeup_filter.h"
#include "lipstick_filter.h"
#include "blusher_filter.h"
#include "face_reshape_filter.h"

#include "box_blur_filter.h"
#include "box_high_pass_filter.h"

// general filters
#include "bilateral_filter.h"
#include "brightness_filter.h"
#include "canny_edge_detection_filter.h"
#include "color_invert_filter.h"
#include "color_matrix_filter.h"
#include "contrast_filter.h"
#include "convolution3x3_filter.h"
#include "crosshatch_filter.h"
#include "directional_non_maximum_suppression_filter.h"
#include "directional_sobel_edge_detection_filter.h"
#include "emboss_filter.h"
#include "exposure_filter.h"
#include "gaussian_blur_filter.h"
#include "gaussian_blur_mono_filter.h"
#include "glass_sphere_filter.h"
#include "grayscale_filter.h"
#include "hsb_filter.h"
#include "halftone_filter.h"
#include "hue_filter.h"
#include "ios_blur_filter.h"
#include "luminance_range_filter.h"
#include "nearby_sampling3x3_filter.h"
#include "non_maximum_suppression_filter.h"
#include "pixellation_filter.h"
#include "posterize_filter.h"
#include "rgb_filter.h"
#include "saturation_filter.h"
#include "single_component_gaussian_blur_filter.h"
#include "single_component_gaussian_blur_mono_filter.h"
#include "sketch_filter.h"
#include "smooth_toon_filter.h"
#include "sobel_edge_detection_filter.h"
#include "sphere_refraction_filter.h"
#include "toon_filter.h"
#include "weak_pixel_inclusion_filter.h"
#include "white_balance_filter.h"
#include "effect_sceen2_filter.h"
#include "effect_glitch_filter.h"
#include "effect_inout_filter.h"
#include "effect_mosaic_filter.h"
#include "effect_opendoor_filter.h"
#include "effect_scale_filter.h"
#include "effect_sceen3_filter.h"
#include "effect_sceen4_filter.h"
#include "effect_sceen6_filter.h"
#include "effect_sceen9_filter.h"
#include "effect_shake_filter.h"
#include "effect_shake_filter.h"
#include "effect_sharpen_filter.h"
#include "effect_shinewhite_filter.h"
#include "effect_soulout_filter.h"
#include "effect_water_filter.h"
#include "sepia_filter.h"
#include "gama_filter.h"
#include "highlight_shadow_filter.h"
#include "vignette_filter.h"
#include "flipX_filter.h"
#include "pass_filter.h"
#include "sticker2d_filter.h"
#include "transform3d_filter.h"
#include "glasses_filter.h"
#include "add_landmarks_filter.h"
#include "eyes_maskone_filter.h"
#include "sticker2d_effect_Clown.h"
#include "sticker2d_effect_Bitie.h"
#include "sticker2d_effect_eyesmask.h"


