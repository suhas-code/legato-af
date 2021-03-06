{#-
 #  Jinja2 template for generating message defines for Legato APIs.
 #
 #  Note: C/C++ comments apply to the generated code.  For example this template itself is not
 #  autogenerated, but the comment is copied verbatim into the generated file when the template is
 #  expanded.
 #
 #  Copyright (C) Sierra Wireless Inc.
 #}
{%- import 'pack.templ' as pack with context -%}
/*
 * ====================== WARNING ======================
 *
 * THE CONTENTS OF THIS FILE HAVE BEEN AUTO-GENERATED.
 * DO NOT MODIFY IN ANY WAY.
 *
 * ====================== WARNING ======================
 */


#ifndef {{apiBaseName|upper}}_MESSAGES_H_INCLUDE_GUARD
#define {{apiBaseName|upper}}_MESSAGES_H_INCLUDE_GUARD


#include "{{apiBaseName}}_common.h"
{% if args.localService %}
#define _MAX_MSG_SIZE IFGEN_{{apiBaseName|upper}}_LOCAL_MSG_SIZE
{%- else %}
#define _MAX_MSG_SIZE IFGEN_{{apiBaseName|upper}}_MSG_SIZE
{%- endif %}

// Define the message type for communicating between client and server
typedef struct __attribute__((packed))
{
    uint32_t id;
    uint8_t buffer[_MAX_MSG_SIZE];
}
_Message_t;
{% for function in functions %}
#define _MSGID_{{apiBaseName}}_{{function.name}} {{loop.index0}}
{%- endfor %}


// Define type-safe pack/unpack functions for all enums, including included types
{%- for type in allTypes if type is EnumType or type is BitMaskType %}
{{ pack.DeclareEnumPackUnpack(type) }}

{%- endfor %}

// Define pack/unpack functions for all structures, including included types
{% for type in allTypes if type is StructType %}
{{ pack.DeclareStructPackUnpack(type) }}

{%- endfor %}

#endif // {{apiBaseName|upper}}_MESSAGES_H_INCLUDE_GUARD
