/*
* fpu_panalyzer.h - branch prediction power analysis 
* 
*
* This file is a part of the PowerAnalyzer tool suite written by
* Taeho Kgil as a part of the PowerAnalyzer Project.
*  
* The tool suite is currently maintained by Taeho Kgil.
* 
* Copyright (C) 2003 by Taeho Kgil
*
* Revised by Taeho Kgil
*
* This source file is distributed "as is" in the hope that it will be
* useful.  The tool set comes with no warranty, and no author or
* distributor accepts any responsibility for the consequences of its
* use. 
* 
* Everyone is granted permission to copy, modify and redistribute
* this tool set under the following conditions:
* 
*    This source code is distributed for non-commercial use only. 
*    Please contact the maintainer for restrictions applying to 
*    commercial use.
*
*    Permission is granted to anyone to make or distribute copies
*    of this source code, either as received or modified, in any
*    medium, provided that all copyright notices, permission and
*    nonwarranty notices are preserved, and that the distributor
*    grants the recipient permission for further redistribution as
*    permitted by this document.
*
*    Permission is granted to distribute this file in compiled
*    or executable form under the same conditions that apply for
*    source code, provided that either:
*
*    A. it is accompanied by the corresponding machine-readable
*       source code,
*    B. it is accompanied by a written offer, with no time limit,
*       to give anyone a machine-readable copy of the corresponding
*       source code in return for reimbursement of the cost of
*       distribution.  This written offer must permit verbatim
*       duplication by anyone, or
*    C. it is distributed by someone who received only the
*       executable form, and is accompanied by a copy of the
*       written offer of source code that they received concurrently.
*
* In other words, you are welcome to use, share and improve this
* source file.  You are forbidden to forbid anyone else to use, share
* and improve what you give them.
*/

#ifndef FPU_PANALYZER_H 
#define FPU_PANALYZER_H
#include "../host.h"
#include "../stats.h"



/* number of virtual address */
#define NVA	40
/* number of physicalo address */
#define NPA 32

/* fpu power specification type:
 * contain all the info for analyzing fpu pdissipation */
typedef struct _fu_fpu_pspec_t {
	char *name; /* name */
	double freq, volt; /* operating frequency/supply voltage */
	double iCeff;
	unsigned long fpu_access;
	double fpu_total_power;
	double fpu_power;
	double max_power;
	double avg_power;
	double pipe_fpu_power[3];
} fu_fpu_pspec_t;

/* create power model fpu panalyzer database
 * return an allocated location pointer.
 * caution: please deallocate the fpu space  */
fu_fpu_pspec_t *
create_fpu_panalyzer(
	char *name, /* fpu name */
	int freq,double volt,
	double iCeff);

/* power model fpu panalyzer */
void 
fpu_panalyzer(
	fu_fpu_pspec_t *pspec,
	tick_t now 
	);
#endif /* FPU_PANALYZER_H */
