/* fruit_infer.dll — NV12 in, YOLOX boxes out. Host allocates buffers. cdecl. */
/* Box: cx,cy,w,h,score,class_id (FI_YOLO_BOX_FLOATS). FI_COORD_SOURCE = full-frame pixels. */
/* One thread for fi_yolo_detect_nv12. lib_dir = directory with onnxruntime.dll. */
#ifndef FRUIT_INFER_H
#define FRUIT_INFER_H

#ifdef __cplusplus
extern "C" {
#endif

#define FI_COORD_SOURCE 0
#define FI_COORD_MODEL 1

#define FI_INFER_API_VERSION 102
#define FI_YOLO_BOX_FLOATS 6

#define FI_OK 0
#define FI_ERR_NOT_INIT -1
#define FI_ERR_BAD_ARG -2
#define FI_ERR_NV12 -3
#define FI_ERR_ORT -4
#define FI_ERR_BUFFER -5
#define FI_ERR_STATE -6

const char *get_engine_license_info(void);
const char *fi_engine_auth_marker(void);

int fi_infer_version(void);

int fi_infer_init(const char *lib_dir, const char *det_model_path,
                  float min_conf, float iou,
                  int ort_intra_threads, int ort_inter_threads);

void fi_infer_shutdown(void);

int fi_ort_export_for_cat(void **out_env, void **out_api);

int fi_yolo_detect_nv12(const unsigned char *nv12, int src_w, int src_h, int stride,
                       int roi_x0, int roi_y0, int roi_x1, int roi_y1,
                       int infer_w, int infer_h,
                       float *out_boxes, int max_boxes, int *out_count,
                       int *out_pad_x, int *out_pad_y, float *out_letterbox_ratio,
                       int coord_mode, float *out_infer_ms, float *out_preprocess_ms,
                       float *out_postprocess_ms);

#ifdef __cplusplus
}
#endif

#endif
