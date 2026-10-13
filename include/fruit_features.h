/* fruit_features.dll — RGB888 in, feature atoms out (44 for apple). Host allocates buffers. */
#ifndef FRUIT_FEATURES_H
#define FRUIT_FEATURES_H

#ifdef __cplusplus
extern "C" {
#endif

#define FI_FEATURES_API_VERSION 2
#define FI_FEATURES_APPLE44 44

#define FI_FEAT_OK 0
#define FI_FEAT_ERR_ARG -1

const char *get_engine_license_info(void);
const char *fi_engine_auth_marker(void);

int fi_features_version(void);
int fi_atom_count(void);
const char *fi_atom_id(int index);
int fi_atom_index_by_id(const char *id);
int fi_atom_group_count(void);
int fi_atom_group(int atom_index);
const char *fi_atom_group_name(int group_id);

int fi_extract_apple44(const unsigned char *rgb, int w, int h, int stride,
                       float *out_feat);

int fi_extract_by_indices(const unsigned char *rgb, int w, int h, int stride,
                          const int *indices, int n, float *out_feat);

#ifdef __cplusplus
}
#endif

#endif
