#ifndef QUANTUM_SIMULATOR_H 
#define QUANTUM_SIMULATOR_H

#include <stdio.h>
#include <complex.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned int q_reg;

#define PI 3.141592653589793

struct q_state {
  double complex *comp;
  q_reg qubits; // The number of qubits used to represent the state
  q_reg length; // The number of comples numbers needed to represent the state = 2^qubits
};


void q_printf(q_reg);

int valid_qubit(q_reg);

/* qstate operations */

struct q_state qstate_create(q_reg);

void qstate_destroy(struct q_state);

struct q_state qstate_clone(struct q_state);

double qstate_min(struct q_state);

double qstate_max(struct q_state);

double qstate_norm(struct q_state);

void qstate_normalize(struct q_state);

double complex qstate_inner(struct q_state, struct q_state);

void qstate_random(struct q_state);

void qstate_print(struct q_state);

void qstate_pure(q_reg, struct q_state);

q_reg qstate_measure(struct q_state);

/* One qubit ops */

void qop_hadamard(q_reg, struct q_state);

void qop_x(q_reg, struct q_state);

void qop_y(q_reg, struct q_state);

void qop_z(q_reg, struct q_state);

void qop_s(q_reg, struct q_state);

void qop_rotation(q_reg, q_reg, double phase, struct q_state);

/* Two qubit ops */

void qop_cnot(q_reg, q_reg, struct q_state);

void qop_swap(q_reg, q_reg, struct q_state);

void qop_rotation(q_reg, q_reg, double phase, struct q_state);

void qop_qft(struct q_state, int);

void qop_oracle(int (*)(q_reg), struct q_state);

void qop_diffusion(struct q_state);

void qop_grover(int (*)(q_reg), struct q_state, q_reg);

unsigned int qop_shor(q_reg);

#endif /* QUANTUM_EMULATOR_H */
