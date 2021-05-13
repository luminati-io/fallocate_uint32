{
  "targets": [{
    "target_name": "fallocate",
    "cflags": ["-Wno-cast-function-type"],
    "sources": ["./src/fallocate.cc"],
    "include_dirs" : ["<!(node -e \"require('nan')\")"]
  }],
}
