#include "m_pd.h"

static t_class *pdhi_class;

typedef struct _pdhi {
    t_object x_obj;
} t_pdhi;

void pdhi_bang(t_pdhi *x) {
    (void)x;
    post("pd hi!");
}

void *pdhi_new(void) {
    t_pdhi *x = (t_pdhi *)pd_new(pdhi_class);
    return (void *)x;
}

void pdhi_setup(void) {
    post("pdhi loaded");
    pdhi_class = class_new(gensym("pdhi"),
                           (t_newmethod)pdhi_new, NULL,
                           sizeof(t_pdhi), CLASS_DEFAULT, 0);
    class_addbang(pdhi_class, pdhi_bang);
}
