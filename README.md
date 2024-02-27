# WW_Run3
PlotConfiguration for WW Run 3 analysis


## Warnings

There have been two issues in the Postprocessing step. They are explained here:

- Lepton working point default value set as **True** instead of False. To deal with this, the `LepCut` aliases must be redefined in aliases.py using `&` instead of `||`.

- Jet collection not correctly created (Several problems with the jet_veto_maps and the PU ID, not existing anymore with Puppi). The jet collection is correctly recreated on-the-fly in runner.py. To solve the issue:

```
cp runner.py $YOUR_WORKDIR/mkShapesRDF/mkShapesRDF/shapeAnalysis/
```

## Run the code

Always compile after making any change in the configuration.

```
mkShapesRDF -c 1

mkShapesRDF -o 0 -f . -b 1

hadd rootFile/... ...

mkPlot
```


