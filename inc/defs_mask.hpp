#ifndef _DEFS_MASK_HPP_
#define _DEFS_MASK_HPP_

#define control_r         '\x01'

#define control_g         '\x02'

#define control_b         '\x04'

#define control_a         '\x08'

#define control_a_rnd     '\x10'

#define on(mask, type)    (mask |= control_##type)

#define full_off(mask)    (mask = '\x00')

#define ifon(mask, type)  (mask &  control_##type)

#define inactive(mask)    (mask == '\x00')

#endif//_DEFS_MASK_HPP_
