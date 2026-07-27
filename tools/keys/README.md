# TI Flash App signing keys

`0104.key` is the free TI-83+/84+ “shareware” application signing key
(from [RabbitSign](https://github.com/abbrev/rabbitsign)). Real calculators
accept apps signed with this key.

App builds call `tools/bin/rabbitsign` (see `tools/install_rabbitsign.sh`).
RabbitSign also embeds key 0104, so the `.key` file is optional.
