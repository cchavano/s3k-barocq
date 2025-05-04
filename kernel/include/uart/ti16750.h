#define LSR_THR_EMPTY 0x20
#define LSR_RBR_READY 0x1

struct uart_ti16750_regs {
	// 0
	union {
		unsigned int rbr;
		unsigned int thr;
		unsigned int dlab_lsb;
	};

	// 4
	union {
		unsigned int interrupt_enable;
		unsigned int dlab_msb;
	};

	// 8
	union {
		unsigned int interrupt_ident;
		unsigned int fifo_control;
	};

	// 12
	unsigned int line_control;
	// 16
	unsigned int modem_control;
	// 20
	unsigned int line_status;
	// 24
	unsigned int modem_status;
};

static int uart_ti16750_putchar(int c, void *base)
{
	volatile struct uart_ti16750_regs *regs = base;
	while (!(regs->line_status & LSR_THR_EMPTY))
		;
	regs->thr = (unsigned char)c;
	return (unsigned char)c;
}
