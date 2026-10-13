/* fruit_cat.dll — 44 floats in, class + score out. */
/* After fi_infer_init: fi_ort_export_for_cat, pass env/api into fi_cat_init (one OrtEnv). */
#ifndef FRUIT_CAT_H
#define FRUIT_CAT_H

#ifdef __cplusplus
extern "C" {
#endif

#define FI_CAT_API_VERSION 100
#define FI_CAT_FEATURE_COUNT 44

#define FI_CAT_OK 0
#define FI_CAT_ERR_NOT_INIT -1
#define FI_CAT_ERR_BAD_ARG -2
#define FI_CAT_ERR_ORT -4

const char *get_engine_license_info(void);
const char *fi_engine_auth_marker(void);

int fi_cat_version(void);

int fi_cat_init(const char *lib_dir_or_dll, const char *cat_model_path,
                void *shared_env, void *shared_api,
                int ort_intra_threads, int ort_inter_threads);

void fi_cat_shutdown(void);

int fi_cat_infer(const float *features, int n_feat, int *out_class_id, float *out_score,
                 float *out_prob0, float *out_prob1, int *out_dense_probs);

#ifdef __cplusplus
}
#endif

#endif
