# Bitsliced AEGIS

Protected implementations of the [AEGIS authenticated encryption algorithms](https://cfrg.github.io/draft-irtf-cfrg-aegis-aead/draft-irtf-cfrg-aegis-aead.html) for platforms without hardware AES support.

Side channels are mitigated using the [barrel-shiftrows](https://eprint.iacr.org/2020/1123.pdf) bitsliced representation recently introduced by Alexandre Adomnicai and Thomas Peyrin, which has proven to be a good fit for all AEGIS-128* variants.

With this representation, AEGIS-128L consistently outperforms AES128-GCM in terms of speed.

ARM Cortex A53:

| Algorithm                 | Speed (Mb/s) |
| :------------------------ | -----------: |
| AES-128-GCM (OpenSSL 3.3) |          129 |
| AEGIS-128L (bitsliced)    |          210 |
| AEGIS-128L (unprotected)  |          427 |

WebAssembly (Apple M1, baseline+simd128):

| Algorithm                            | Speed (Mb/s) |
| :----------------------------------- | -----------: |
| AES-128-GCM (rust-crypto, fixsliced) |          472 |
| AES-128-GCM (unprotected)            |         1040 |
| AEGIS-128L (bitsliced)               |         2215 |
| AEGIS-128L (unprotected)             |         4232 |
