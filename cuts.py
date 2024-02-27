
cuts = {}


preselections = 'Lepton_pt[0]>25 && Lepton_pt[1]>20\
            && abs(Lepton_eta[0])<2.5 && fabs(Lepton_eta[1])<2.5 \
            && Alt(Lepton_pt, 2, 0)<10.0 '


cuts['Z']  = {
    'expr' : 'mll>60 && mll<120',
    'categories' : {
        'ee' : '(Lepton_pdgId[0] * Lepton_pdgId[1] == -11*11)',
        'mm' : '(Lepton_pdgId[0] * Lepton_pdgId[1] == -13*13)',
    }
}

cuts['ss']  = {
    'expr' : '(Lepton_pdgId[0] * Lepton_pdgId[1] == 11*13) && mll>85 && bVeto',
    'categories' : {
        'em' : '(Lepton_pdgId[0] * Lepton_pdgId[1] == 11*13)',
    }
}

'''
cuts['Top']  = {
    'expr' : '(Lepton_pdgId[0] * Lepton_pdgId[1] == -11*13) && topcr',
    'categories' : {
        '0j' : 'Alt(CleanJet_pt,0,0)<30',
        '1j' : 'Alt(CleanJet_pt,0,0)>30 && Alt(CleanJet_pt,1,0)<30',
        '2j' : 'Alt(CleanJet_pt,1,0)>30',
    }
}

cuts['DY']  = {
    'expr' : '(Lepton_pdgId[0] * Lepton_pdgId[1] == -11*13) && mll<85 && bVeto && ptll<30',
    'categories' : {
        '0j' : 'Alt(CleanJet_pt,0,0)<30',
        '1j' : 'Alt(CleanJet_pt,0,0)>30 && Alt(CleanJet_pt,1,0)<30',
        '2j' : 'Alt(CleanJet_pt,1,0)<30',
    }
}

cuts['WW']  = {
    'expr' : '(Lepton_pdgId[0] * Lepton_pdgId[1] == -11*13) && mll>85 && bVeto',
    'categories' : {
        '0j' : 'Alt(CleanJet_pt,0,0)<30',
        '1j' : 'Alt(CleanJet_pt,0,0)>30 && Alt(CleanJet_pt,1,0)<30',
        '2j' : 'Alt(CleanJet_pt,1,0)<30',
    }
}
'''

cuts['Top_Inc']  = {
    'expr' : '(Lepton_pdgId[0] * Lepton_pdgId[1] == -11*13) && topcr',
    'categories' : {
        'prompt' :'Lepton_pt[0]>20'
    }
}

cuts['DY_Inc']  = {
    'expr' : '(Lepton_pdgId[0] * Lepton_pdgId[1] == -11*13) && mll<85 && bVeto && ptll<30',
    'categories' : {
        'prompt' : 'Lepton_pt[0]>20'
    }
}

cuts['WW_Inc']  = {
    'expr' : '(Lepton_pdgId[0] * Lepton_pdgId[1] == -11*13) && mll>85 && bVeto',
    'categories' : {
        'prompt' : 'Lepton_pt[0]>20'
    }
}

cuts['preSR_Inc']  = {
    'expr' : '(Lepton_pdgId[0] * Lepton_pdgId[1] == -11*13) && mll>85',
    'categories' : {
        'prompt' : 'Lepton_pt[0]>20'
    }
}
