from numpy import ma
from numpy import exp

from lmfit import Parameters
import lmfit
import time
import os
from astropy import units as u
from corefit.model import Model,MultiModel

mm = MultiModel()
mm.init('conf/sets/121_loc_spi_32.json') #121_loc_spin
m = mm.models[0]


from numpy import log10
params = Parameters()
params.load(open('params/121_sq_rot.prs'))

"""
for p, val in prs.items():
    params.add(p, val)

params_to_delete = ['vlsr', 'ra', 'dec']
for param in params_to_delete:
    if param in params:
        del params[param]

from corefit.model import RadialCustomParam

def vturb(r):
    ret = 5.3*(1-exp(-exp(-(r*u.cm.to(u.pc)/1.4)**2)))/1.665
    ret[ret<1.2/1.665] = 1.2/1.665
    return ret


rcp = RadialCustomParam(vturb)
for m in mm:
    m.params.VTURB = rcp
    #m.params.limits.pop('VTURB')
    m.params.vrot.a=0.1
    m.params.frame = 'fk5'
"""

#from corefit.model import RadialFragmentedParam
#rcp = RadialFragmentedParam(1,var=m.params.DENS.p0,a=m.params.DENS.a,R0=m.params.R0)
#m.params.DENS = rcp
#m.conf.subg = 5


mm(params)

from corefit.visual import complex_draw   
from matplotlib import pyplot as plt      

fig, ax = plt.subplots(figsize=(8,8))
complex_draw(mm.models[0])