#pragma once
/**
 * @file proc.h
 * @brief Defines the process control block and its associated functions.
 *
 * This file contains the definition of the `proc_t` data structure, which
 * represents a process control block (PCB) in the operating system. It also
 * contains the declarations of functions for manipulating the PCB.
 *
 * @copyright MIT License
 */

#include "types.h"

typedef word_t proc_state_t;

typedef enum {
	PSF_BUSY = 1,
	PSF_BLOCKED = 2,
	PSF_SUSPENDED = 4,
} proc_state_flag_t;

typedef struct regs {
	word_t pc, ra, sp, gp, tp;
	word_t t0, t1, t2, s0, s1;
	word_t a0, a1, a2, a3, a4, a5, a6, a7;
	word_t s2, s3, s4, s5, s6, s7, s8, s9;
	word_t s10, s11, t3, t4, t5, t6;
	word_t tpc, tsp, epc, esp;
	word_t ecause, eval;
	word_t servtime;
} regs_t;

typedef struct pmp {
	uint8_t cfg[S3K_PMP_CNT];
	word_t addr[S3K_PMP_CNT];
} pmp_t;

/**
 * @brief Process control block.
 *
 * Contains all information needed manage a process except the capabilities.
 */
typedef struct {
	/** Process state. */
	proc_state_t state;
	/** The registers of the process (RISC-V registers and virtual
	 * registers). */
	regs_t regs;
	/** PMP registers */
	pmp_t pmp;
	/** Instrumentation registers */
	/** Process ID. */
	pid_t pid;

	/** Scheduling information */
	uint64_t timeout;
	/**
	 * Minimum remaining time required for receiving messages.
	 * If a client does not have sufficient execution time,
	 * it is not allowed to send the message.
	 */
	uint64_t serv_time;
} proc_t;

/**
 * Initializes all processes in the system.
 *
 * @note This function should be called only once during system startup.
 */
void proc_init(word_t payload);

/**
 * @brief Gets the process corresponding to a given process ID.
 *
 * @param pid The process ID to look for.
 * @return A pointer to the process corresponding to the given PID.
 */
proc_t *proc_get(pid_t pid);

proc_state_t proc_get_state(proc_t *proc);

bool proc_acquire(proc_t *proc);
void proc_release(proc_t *proc);
void proc_suspend(proc_t *proc);
void proc_resume(proc_t *proc);
void proc_ipc_wait(proc_t *proc, chan_t chan);
bool proc_ipc_acquire(proc_t *proc, chan_t chan);
bool proc_is_suspended(proc_t *proc);

bool proc_pmp_avail(proc_t *proc, pmp_slot_t slot);
void proc_pmp_load(proc_t *proc, pmp_slot_t slot, rwx_t cfg, napot_t addr);
void proc_pmp_unload(proc_t *proc, pmp_slot_t slot);
void proc_pmp_sync(proc_t *proc);
