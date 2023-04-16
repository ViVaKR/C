# `C` Examples


### VSCode User `Snippets`
```json
{
  "Viv Printf Number": {
    "prefix": "pfd",
    "body": [
      "printf(\"${1:Text} \\%d\\n\",${2:var});$0"
    ],
    "description": "Viv printf number"
  },
  "Viv Printf String": {
    "prefix": "pfs",
    "body": [
      "printf(\"${1:Text} \\%s\\n\",${2:var});$0"
    ],
    "description": "Viv printf string"
  },
  "Viv Printf Double": {
    "prefix": "pfs",
    "body": [
      "printf(\"${1:Text} \\%f.2\\n\",${2:var});$0"
    ],
    "description": "Viv printf string"
  },
  "Viv Printf Blank": {
    "prefix": "pfb",
    "body": [
      "printf(\"${1:\\n}\");$0"
    ],
    "description": "Viv printf blank"
  },
  "Viv Scanf": {
    "prefix": "sf",
    "body": [
      "scanf(\"%d\", ${1:var});$0"
    ],
    "description": "Viv blank line with scanf"
  },
  "Viv #include": {
    "prefix": "#i",
    "body": [
      "#include <stdio.h>",
      "#include <stdlib.h>"
    ],
    "description": "Viv default #includes"
  },
  "Viv function": {
    "prefix": "fc",
    "body": [
      "void ${1:name}()",
      "{",
      "\t$0",
      "}"
    ],
    "description": "Viv create function"
  }
}
```

### [Ref : Bro Code](https://youtu.be/87SH2Cn0s9A)
