/////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2002-2004 Xilinx, Inc.  All rights reserved.
//
// Xilinx, Inc.
//
// XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS" AS A 
// COURTESY TO YOU.  BY PROVIDING THIS DESIGN, CODE, OR INFORMATION AS
// ONE POSSIBLE   IMPLEMENTATION OF THIS FEATURE, APPLICATION OR 
// STANDARD, XILINX IS MAKING NO REPRESENTATION THAT THIS IMPLEMENTATION
// IS FREE FROM ANY CLAIMS OF INFRINGEMENT, AND YOU ARE RESPONSIBLE 
// FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE FOR YOUR IMPLEMENTATION.  
// XILINX EXPRESSLY DISCLAIMS ANY WARRANTY WHATSOEVER WITH RESPECT TO 
// THE ADEQUACY OF THE IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO 
// ANY WARRANTIES OR REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE 
// FROM CLAIMS OF INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY 
// AND FITNESS FOR A PARTICULAR PURPOSE.
/////////////////////////////////////////////////////////////////////////////

#ifndef __FAT_H_
#define __FAT_H_

#include "sysace.h"
#include "part.h"
#include "directory.h"
#include "fsinfo.h"

#define MAX_BYTES_PER_CLUSTER	(32*1024)

#define MAX_FAT12_CLUSTERS	0x0FF5
#define MAX_FAT16_CLUSTERS	0xFFF5
#define MAX_FAT32_CLUSTERS	0x0FFFFFF5

#define FAT12_BAD_CLUSTER	0x0FF7
#define FAT16_BAD_CLUSTER	0xFFF7
#define FAT32_BAD_CLUSTER	0x0FFFFFF7

#define FAT12_EOC	0x0FF8
#define FAT16_EOC	0xFFF8
#define FAT32_EOC	0x0FFFFFF8

/* defined for convenience, not per spec */
#define BAD_CLUSTER		0xFFFFFFFF	


#ifdef __cplusplus
extern "C" {
#endif

/* FAT file system info present in a FAT partition */
typedef struct _BiosParameterBlock {
	BYTE  BytesPerSector[2];
	BYTE  SectorsPerCluster;
	BYTE  ReservedSector[2];
	BYTE  NumberOfFats;
	BYTE  RootDirCount[2];
	BYTE  TotalSectors16[2];
	BYTE  MediaType;          
	BYTE  SectorsPerFat[2];
	BYTE  SectorsPerTrack[2];
	BYTE  NumberOfHeads[2];
	BYTE  NumberOfHiddenSect[4];
	BYTE  TotalSectors32[4];

	/* following fields are present only in FAT32 */
	BYTE  SectorsPerFat_32[4];
	BYTE  ExtFlags[2];
	BYTE  FSVer[2];
	BYTE  RootCluster[4];
	BYTE  FSInfo[2];
	BYTE  BkBootSector[2];
	BYTE  Reserved[12];

} __attribute__((packed)) BiosParameterBlock;

/* organization of the first sector of a FAT partition */
typedef struct  _PartitionBootRecord { 	
	BYTE                	JMPCode[3];
	BYTE                	OEMNameVersion[8];
	BiosParameterBlock  	BPB;
	BYTE                	DriverNumber;
	BYTE             	Reserved;
	BYTE              	ExtendBootSig;
	BYTE               	VolID[4];
	BYTE                	VolLable[11];
	BYTE           	    	FileSysType[8];
	BYTE           	    	BootCode[420];
	BYTE           	    	BootCodeSignature[2];
} __attribute__((packed)) PartitionBootRecord;

/* Information about the current working directory */
#define MAXFILENAMESIZE 13   // 8.3 plus a trailing 0

typedef struct _WorkingDirectory { 
	char name[MAXFILENAMESIZE];

	/* If this is null, this is a root directory */
	struct _WorkingDirectory *parent;

	/* This is a pointer to statically allocated information - never free */
	PartitionInfo *pi;  

	union { 
		struct { /* These values are only defined for a root directory */
			UINT32 StartSector;
			UINT16 DirCount;
		} root;

		struct { /* These values are only defined for a child directory */
			UINT32 FirstCluster;
			UINT32 FileSize;
			DirectoryEntryLocation	DirLocation;
		} child;
	} v;
} WorkingDirectory;

UINT32 next_cluster(UINT32 cluster, PartitionInfo *pi);
UINT32 starting_sector(UINT32 cluster, PartitionInfo *pi);

PartitionInfo *get_partition_info(int partition);
int find_in_directory(WorkingDirectory *wd, const char *name, 
		const char *ext, UINT32 *firstcluster, UINT32 *filesize, 
		UINT32 *de_sector, UINT32 *de_offset);
void delete_working_directory_stack(WorkingDirectory *wd);
WorkingDirectory *build_working_directory_stack(const char *path, int is_dir, int is_write);
WorkingDirectory *make_root_directory(int partition);
WorkingDirectory *make_child_directory(const char *name, const char *ext, WorkingDirectory *parent);
WorkingDirectory *copy_directory_stack(WorkingDirectory *stack);
WorkingDirectory *create_file_entry(const char *name, const char *ext,
			  WorkingDirectory *parent, BYTE attributes);
WorkingDirectory *_build_working_directory_stack(const char *path,
                          int is_dir, int create);
int is_dir_empty(WorkingDirectory *wd);


/* FIXME */
UINT32 allocate_one_cluster(PartitionInfo *pi);
void initialize_de(DirectoryEntry *de, char *name, char *ext, 
		UINT32 firstcluster, UINT32 filesize, PartitionInfo *pi, BYTE attrib);

int link_cluster(UINT32 from_cluster, UINT32 to_cluster, PartitionInfo *pi);
int truncate_file(UINT32 cluster, PartitionInfo *pi);

UINT32 next_cluster_generic(UINT32 cluster, PartitionInfo * pi);
int free_cluster_chain_generic(UINT32 cluster, PartitionInfo *pi);
UINT32 allocate_one_cluster_generic(PartitionInfo *pi);
int link_cluster_generic(UINT32 from_cluster, UINT32 to_cluster, PartitionInfo *pi);

extern WorkingDirectory *cwd[MAXPARTITION];
extern int DefaultPartition;
extern DirectoryEntry dotdot_entry[2];


#ifdef __cplusplus
}
#endif

#endif 
