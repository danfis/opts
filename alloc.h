/***
 * fermat
 * -------
 * Copyright (c)2010 Daniel Fiser <danfis@danfis.cz>
 *
 *  This file is part of fermat.
 *
 *  Distributed under the OSI-approved BSD License (the "License");
 *  see accompanying file BDS-LICENSE for details or see
 *  <http://www.opensource.org/licenses/bsd-license.php>.
 *
 *  This software is distributed WITHOUT ANY WARRANTY; without even the
 *  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *  See the License for more information.
 */

#ifndef __FER_ALLOC_H__
#define __FER_ALLOC_H__

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * Alloc - Memory Allocation
 * ==========================
 *
 * Functions and macros for memory allocation.
 */

/* Memory allocation: - internal macro */
#define _FER_ALLOC_MEMORY(type, ptr_old, size) \
    (type *)realloc((void *)ptr_old, (size))

/**
 * Allocate memory for one element of given type.
 */
#define FER_ALLOC(type) \
    _FER_ALLOC_MEMORY(type, NULL, sizeof(type))

/**
 * Allocate array of elements of given type.
 */
#define FER_ALLOC_ARR(type, num_elements) \
    _FER_ALLOC_MEMORY(type, NULL, sizeof(type) * (num_elements))

/**
 * Reallocates array.
 */
#define FER_REALLOC_ARR(ptr, type, num_elements) \
    _FER_ALLOC_MEMORY(type, ptr, sizeof(type) * (num_elements))

#define FER_FREE(ptr) free(ptr) /*!< Deallocates memory */

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* __FER_ALLOC_H__ */
