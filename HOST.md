# hookup

Windows x64. Paths below are examples — use your unzip dir.

```
ORT_DIR   = ...\lib\cpu          (onnxruntime.dll lives here)
DET_ONNX  = ...\model\apple\det.onnx
CAT_ONNX  = ...\model\apple\cat.onnx
```

Load all three from `bin\`. Keep them loaded until exit.

Init once:

1. `fi_infer_init(ORT_DIR, DET_ONNX, min_conf, iou, intra, inter)` — often 0.6, 0.5, threads 0.  
2. `fi_ort_export_for_cat(&env, &api)`  
3. `fi_cat_init(ORT_DIR, CAT_ONNX, env, api, intra, inter)`

Shutdown: `fi_cat_shutdown` → `fi_infer_shutdown` → FreeLibrary.

Per frame: NV12 in (Y + UV, stride ≥ width) → `fi_yolo_detect_nv12` with `FI_COORD_SOURCE` → pick a box (your rule) → your RGB crop → `fi_extract_apple44` (or `fi_extract_by_indices` if you follow `features.json`) → `fi_cat_infer`.

Full-frame detect: roi with x1 < x0 — see `fruit_infer.h`.

Exports worth knowing: `get_engine_license_info`, `fi_engine_auth_marker`. Don't strip dll metadata; eval license is clear on that.

Not in the dll yet: NV12→RGB inside features, detect from a file without NV12.

Return codes and struct layout: headers only.
