/* 
 *	HT Editor
 *	pestruct.cc
 *
 *	Copyright (C) 1999-2002 Stefan Weyergraf
 *
 *	This program is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License version 2 as
 *	published by the Free Software Foundation.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with this program; if not, write to the Free Software
 *	Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */


#include "endianess.h"
#include "pestruct.h"
#include "coff_s.h"

byte PE_DATA_DIRECTORY_struct[] = {
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	0
};


byte PE_OPTIONAL_HEADER32_NT_struct[] = {
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_16 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_16 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_16 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_16 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_16 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_16 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_16 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_16 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	0
};

byte PE_OPTIONAL_HEADER64_NT_struct[] = {
	STRUCT_ENDIAN_64 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_16 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_16 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_16 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_16 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_16 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_16 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_16 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_16 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_64 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_64 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_64 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_64 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	0
};


byte PE_EXPORT_DIRECTORY_struct[] = {
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_16 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_16 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	0
};

byte PE_THUNK_DATA_struct[] = {
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	0
};

byte PE_THUNK_DATA_64_struct[] = {
	STRUCT_ENDIAN_64 | STRUCT_ENDIAN_HOST,
	0
};

byte PE_IMPORT_DESCRIPTOR_struct[] = {
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	0
};

byte PE_DELAY_IMPORT_DESCRIPTOR_struct[] = {
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	0
};

byte PE_RESOURCE_DIRECTORY_struct[] = {
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_16 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_16 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_16 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_16 | STRUCT_ENDIAN_HOST,
	0
};

byte PE_RESOURCE_DIRECTORY_ENTRY_struct[] = {
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	0
};

byte PE_RESOURCE_DATA_ENTRY_struct[] = {
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	0
};	

byte PE_IL_DIRECTORY_struct[] = {
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_16 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_16 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	STRUCT_ENDIAN_32 | STRUCT_ENDIAN_HOST,
	0
};