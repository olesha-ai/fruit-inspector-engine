# fruit-inspector-engine

Windows x64 **DLLs** for your own inspection UI — detect → features → classify. Same stack I run in [**fruit-inspector-demo**](https://github.com/olesha-ai/fruit-inspector-demo), but **your** app: C#, Delphi, whatever. **No Nim** in your process.

**Download:** [Releases](https://github.com/olesha-ai/fruit-inspector-engine/releases) → **`fruit-inspector-sdk-win64.zip`**. After unzip, keep **`bin/`** and **`lib/cpu/`** as separate folders.

---

I got tired of pipelines where you're second-class without CUDA. Here inference is **CPU via ONNX Runtime** — put `onnxruntime.dll` under `lib/cpu`, point init at that directory. **No GPU required.**

These libraries are **not a reference design** and **not perfect**. **But a start is on the table** — that's what matters to me.

## What's in the release zip

```
bin/            fruit_infer.dll, fruit_cat.dll, fruit_features.dll
lib/cpu/        onnxruntime.dll
include/        fruit_*.h
model/apple/    det.onnx, cat.onnx, features.json, PACK.txt
licenses/       eval + ORT / YOLOX / LightGBM — ship the whole folder
```

| DLL | Role |
|-----|------|
| **fruit_infer.dll** | NV12 frame → YOLOX boxes (axis-aligned, not Ultralytics OBB) |
| **fruit_features.dll** | RGB crop → 44 floats (apple pack) |
| **fruit_cat.dll** | 44 floats → class + score |

**Hookup:** [HOST.md](HOST.md) · **C API:** [include/](include/)

## Not in this repo's zip

- **Fruit_Inspector.exe** — camera + conveyor demo → [fruit-inspector-demo](https://github.com/olesha-ai/fruit-inspector-demo)
- Sample C# / C++ project — headers only; you load the DLLs yourself
- Linux / ARM — this package is **win64** only
- NV12 → RGB crop inside the DLL — **you** crop for now (min 5×5)

## License

**Non-commercial evaluation** — read [LICENSE.md](LICENSE.md) and [licenses/ENGINE_EVAL_LICENSE.md](licenses/ENGINE_EVAL_LICENSE.md) **before** `LoadLibrary`.

Production line / OEM → separate written agreement with **olesha-ai** ([`license-inquiry`](https://github.com/olesha-ai/fruit-inspector-engine/issues/new) issue or [profile](https://github.com/olesha-ai)).

At startup call **`get_engine_license_info()`** once (any of the three DLLs). Don't strip file metadata.

## API versions (this drop)

`fi_infer_version()` **102** · `fi_cat_version()` **100** · `fi_features_version()` **2** — see [VERSION.txt](VERSION.txt)

---

**If you're wiring this into your own code** — you'll get there. I know you will.

Issues welcome from people who actually integrate — bugs, speed, API friction.
