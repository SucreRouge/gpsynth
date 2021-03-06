/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "GPPluginEditorComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
GeneticProgrammingSynthesizerComponent::GeneticProgrammingSynthesizerComponent ()
{
    addAndMakeVisible (fitness = new Slider ("fitness"));
    fitness->setRange (0, 1, 0.01);
    fitness->setSliderStyle (Slider::LinearHorizontal);
    fitness->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    fitness->addListener (this);

    addAndMakeVisible (algonum = new Slider ("algonum"));
    algonum->setRange (0, 9, 1);
    algonum->setSliderStyle (Slider::LinearHorizontal);
    algonum->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    algonum->addListener (this);

    addAndMakeVisible (title = new Label ("title",
                                          "evosynth"));
    title->setFont (Font (45.00f, Font::plain));
    title->setJustificationType (Justification::centred);
    title->setEditable (false, false, false);
    title->setColour (Label::textColourId, Colour (0xff4a9a2d));
    title->setColour (TextEditor::textColourId, Colours::black);
    title->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (algolabel = new Label ("algolabel",
                                              "algorithm"));
    algolabel->setFont (Font (12.00f, Font::plain));
    algolabel->setJustificationType (Justification::centredLeft);
    algolabel->setEditable (false, false, false);
    algolabel->setColour (Label::textColourId, Colour (0xff637fe8));
    algolabel->setColour (TextEditor::textColourId, Colours::black);
    algolabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (fitlabel = new Label ("fitlabel",
                                             "fitness"));
    fitlabel->setFont (Font (12.00f, Font::plain));
    fitlabel->setJustificationType (Justification::centred);
    fitlabel->setEditable (false, false, false);
    fitlabel->setColour (Label::textColourId, Colour (0xff637fe8));
    fitlabel->setColour (TextEditor::textColourId, Colours::black);
    fitlabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (gasetlabel = new Label ("gasetlabel",
                                               "genetic algorithm settings"));
    gasetlabel->setFont (Font (15.00f, Font::plain));
    gasetlabel->setJustificationType (Justification::centred);
    gasetlabel->setEditable (false, false, false);
    gasetlabel->setColour (Label::textColourId, Colours::white);
    gasetlabel->setColour (TextEditor::textColourId, Colours::black);
    gasetlabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (playsetlabel = new Label ("playsetlabel",
                                                 "playback settings"));
    playsetlabel->setFont (Font (15.00f, Font::plain));
    playsetlabel->setJustificationType (Justification::centred);
    playsetlabel->setEditable (false, false, false);
    playsetlabel->setColour (Label::textColourId, Colours::white);
    playsetlabel->setColour (TextEditor::textColourId, Colours::black);
    playsetlabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (gain = new Slider ("gain"));
    gain->setRange (0, 1, 0.01);
    gain->setSliderStyle (Slider::LinearHorizontal);
    gain->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    gain->addListener (this);

    addAndMakeVisible (gainlabel = new Label ("gainlabel",
                                              "gain"));
    gainlabel->setFont (Font (12.00f, Font::plain));
    gainlabel->setJustificationType (Justification::centredLeft);
    gainlabel->setEditable (false, false, false);
    gainlabel->setColour (Label::textColourId, Colour (0xff637fe8));
    gainlabel->setColour (TextEditor::textColourId, Colours::black);
    gainlabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (save = new TextButton ("save"));
    save->setButtonText ("save algorithm");
    save->addListener (this);
    save->setColour (TextButton::buttonColourId, Colour (0xff7575e8));
    save->setColour (TextButton::buttonOnColourId, Colour (0xff0606e6));

    addAndMakeVisible (logo = new ImageButton ("logo"));
    logo->setButtonText (String::empty);

    logo->setImages (false, true, true,
                     ImageCache::getFromMemory (sine_png, sine_pngSize), 1.000f, Colour (0x00000000),
                     Image(), 1.000f, Colour (0x00000000),
                     Image(), 1.000f, Colour (0x00000000));
    addAndMakeVisible (load = new TextButton ("load"));
    load->setButtonText ("load algorithm");
    load->addListener (this);
    load->setColour (TextButton::buttonColourId, Colour (0xff7575e8));
    load->setColour (TextButton::buttonOnColourId, Colour (0xff0606e6));

    addAndMakeVisible (RHSlabel = new Label ("RHSlabel",
                                             CharPointer_UTF8 ("\xc2\xa9 2013 chris donahue")));
    RHSlabel->setFont (Font (10.00f, Font::plain));
    RHSlabel->setJustificationType (Justification::centred);
    RHSlabel->setEditable (false, false, false);
    RHSlabel->setColour (Label::textColourId, Colours::white);
    RHSlabel->setColour (TextEditor::textColourId, Colours::black);
    RHSlabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (nextgen = new TextButton ("nextgen"));
    nextgen->setButtonText ("next generation >>");
    nextgen->addListener (this);
    nextgen->setColour (TextButton::buttonColourId, Colour (0xff7575e8));
    nextgen->setColour (TextButton::buttonOnColourId, Colour (0xff0606e6));

    addAndMakeVisible (prevgen = new TextButton ("prevgen"));
    prevgen->setButtonText ("<< prev generation");
    prevgen->addListener (this);
    prevgen->setColour (TextButton::buttonColourId, Colour (0xff7575e8));
    prevgen->setColour (TextButton::buttonOnColourId, Colour (0xff0606e6));

    addAndMakeVisible (edit = new TextButton ("edit"));
    edit->addListener (this);
    edit->setColour (TextButton::buttonColourId, Colour (0xff7575e8));
    edit->setColour (TextButton::buttonOnColourId, Colour (0xff0606e6));

    addAndMakeVisible (random = new TextButton ("random"));
    random->addListener (this);
    random->setColour (TextButton::buttonColourId, Colour (0xff7575e8));
    random->setColour (TextButton::buttonOnColourId, Colour (0xff0606e6));


    //[UserPreSize]
	algonum->removeListener (this);
	algonum->setRange (0, POPULATIONSIZE - 1, 1);
	algonum->addListener (this);
    //[/UserPreSize]

    setSize (400, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

GeneticProgrammingSynthesizerComponent::~GeneticProgrammingSynthesizerComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    fitness = nullptr;
    algonum = nullptr;
    title = nullptr;
    algolabel = nullptr;
    fitlabel = nullptr;
    gasetlabel = nullptr;
    playsetlabel = nullptr;
    gain = nullptr;
    gainlabel = nullptr;
    save = nullptr;
    logo = nullptr;
    load = nullptr;
    RHSlabel = nullptr;
    nextgen = nullptr;
    prevgen = nullptr;
    edit = nullptr;
    random = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void GeneticProgrammingSynthesizerComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::black);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void GeneticProgrammingSynthesizerComponent::resized()
{
    fitness->setBounds (80, 170, 300, 24);
    algonum->setBounds (80, 140, 160, 24);
    title->setBounds (112, 50, 176, 46);
    algolabel->setBounds (6, 140, 68, 24);
    fitlabel->setBounds (10, 168, 64, 24);
    gasetlabel->setBounds (110, 110, 180, 20);
    playsetlabel->setBounds (133, 220, 134, 22);
    gain->setBounds (80, 250, 300, 24);
    gainlabel->setBounds (32, 250, 32, 24);
    save->setBounds (25, 300, 150, 24);
    logo->setBounds (0, 5, 400, 40);
    load->setBounds (25, 335, 150, 24);
    RHSlabel->setBounds (270, 370, 120, 25);
    nextgen->setBounds (225, 300, 150, 24);
    prevgen->setBounds (225, 335, 150, 24);
    edit->setBounds (240, 140, 50, 24);
    random->setBounds (300, 140, 70, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void GeneticProgrammingSynthesizerComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
	sliderListener->sliderValueChanged(sliderThatWasMoved);
	// verified that things are fine at this point
	// appendToTextFile("./debug.txt", sliderThatWasMoved->getName() + String("\n"));
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == fitness)
    {
        //[UserSliderCode_fitness] -- add your slider handling code here..
        //[/UserSliderCode_fitness]
    }
    else if (sliderThatWasMoved == algonum)
    {
        //[UserSliderCode_algonum] -- add your slider handling code here..
        //[/UserSliderCode_algonum]
    }
    else if (sliderThatWasMoved == gain)
    {
        //[UserSliderCode_gain] -- add your slider handling code here..
        //[/UserSliderCode_gain]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void GeneticProgrammingSynthesizerComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
	buttonListener->buttonClicked(buttonThatWasClicked);
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == save)
    {
        //[UserButtonCode_save] -- add your button handler code here..
        //[/UserButtonCode_save]
    }
    else if (buttonThatWasClicked == load)
    {
        //[UserButtonCode_load] -- add your button handler code here..
        //[/UserButtonCode_load]
    }
    else if (buttonThatWasClicked == nextgen)
    {
        //[UserButtonCode_nextgen] -- add your button handler code here..
        //[/UserButtonCode_nextgen]
    }
    else if (buttonThatWasClicked == prevgen)
    {
        //[UserButtonCode_prevgen] -- add your button handler code here..
        //[/UserButtonCode_prevgen]
    }
    else if (buttonThatWasClicked == edit)
    {
        //[UserButtonCode_edit] -- add your button handler code here..
        //[/UserButtonCode_edit]
    }
    else if (buttonThatWasClicked == random)
    {
        //[UserButtonCode_random] -- add your button handler code here..
        //[/UserButtonCode_random]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void GeneticProgrammingSynthesizerComponent::setSliderListener(SliderListener* sl) {
	sliderListener = sl;
}

void GeneticProgrammingSynthesizerComponent::setButtonListener(ButtonListener* bl) {
	buttonListener = bl;
}

void GeneticProgrammingSynthesizerComponent::getSliders(std::map<String, Slider*>& sliders) {
	sliders["algorithm"] = algonum;
	sliders["fitness"] = fitness;
	sliders["gain"] = gain;
}

void GeneticProgrammingSynthesizerComponent::getButtons(std::map<String, Button*>& buttons) {
	buttons["edit"] = edit;
	buttons["random"] = random;
	buttons["save"] = save;
	buttons["load"] = load;
	buttons["prevgen"] = prevgen;
	buttons["nextgen"] = nextgen;
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="GeneticProgrammingSynthesizerComponent"
                 componentName="" parentClasses="public Component" constructorParams=""
                 variableInitialisers="" snapPixels="10" snapActive="1" snapShown="1"
                 overlayOpacity="0.330000013" fixedSize="1" initialWidth="400"
                 initialHeight="400">
  <BACKGROUND backgroundColour="ff000000"/>
  <SLIDER name="fitness" id="16a1b0db54c88216" memberName="fitness" virtualName=""
          explicitFocusOrder="0" pos="80 170 300 24" min="0" max="1" int="0.01"
          style="LinearHorizontal" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="algonum" id="58d24870e11eeb51" memberName="algonum" virtualName=""
          explicitFocusOrder="0" pos="80 140 160 24" min="0" max="9" int="1"
          style="LinearHorizontal" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="title" id="64fb69a603b235c5" memberName="title" virtualName=""
         explicitFocusOrder="0" pos="112 50 176 46" textCol="ff4a9a2d"
         edTextCol="ff000000" edBkgCol="0" labelText="evosynth" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="45" bold="0" italic="0" justification="36"/>
  <LABEL name="algolabel" id="26fd3e265f6c4c7d" memberName="algolabel"
         virtualName="" explicitFocusOrder="0" pos="6 140 68 24" textCol="ff637fe8"
         edTextCol="ff000000" edBkgCol="0" labelText="algorithm" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="0" italic="0" justification="33"/>
  <LABEL name="fitlabel" id="4461d1426f065552" memberName="fitlabel" virtualName=""
         explicitFocusOrder="0" pos="10 168 64 24" textCol="ff637fe8"
         edTextCol="ff000000" edBkgCol="0" labelText="fitness" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="0" italic="0" justification="36"/>
  <LABEL name="gasetlabel" id="180d29bebe10a4cf" memberName="gasetlabel"
         virtualName="" explicitFocusOrder="0" pos="110 110 180 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="genetic algorithm settings"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
  <LABEL name="playsetlabel" id="4b4f0b44a043419a" memberName="playsetlabel"
         virtualName="" explicitFocusOrder="0" pos="133 220 134 22" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="playback settings"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
  <SLIDER name="gain" id="95c3e13e05b5350b" memberName="gain" virtualName=""
          explicitFocusOrder="0" pos="80 250 300 24" min="0" max="1" int="0.01"
          style="LinearHorizontal" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="gainlabel" id="8fa2033431b21d08" memberName="gainlabel"
         virtualName="" explicitFocusOrder="0" pos="32 250 32 24" textCol="ff637fe8"
         edTextCol="ff000000" edBkgCol="0" labelText="gain" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="save" id="55746809785deaaa" memberName="save" virtualName=""
              explicitFocusOrder="0" pos="25 300 150 24" bgColOff="ff7575e8"
              bgColOn="ff0606e6" buttonText="save algorithm" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <IMAGEBUTTON name="logo" id="a545b1fcad830a39" memberName="logo" virtualName=""
               explicitFocusOrder="0" pos="0 5 400 40" buttonText="" connectedEdges="0"
               needsCallback="0" radioGroupId="0" keepProportions="1" resourceNormal="sine_png"
               opacityNormal="1" colourNormal="0" resourceOver="" opacityOver="1"
               colourOver="0" resourceDown="" opacityDown="1" colourDown="0"/>
  <TEXTBUTTON name="load" id="50cb436ea9e66b16" memberName="load" virtualName=""
              explicitFocusOrder="0" pos="25 335 150 24" bgColOff="ff7575e8"
              bgColOn="ff0606e6" buttonText="load algorithm" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <LABEL name="RHSlabel" id="c93e434e2bed1556" memberName="RHSlabel" virtualName=""
         explicitFocusOrder="0" pos="270 370 120 25" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="&#169; 2013 chris donahue"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="10" bold="0" italic="0" justification="36"/>
  <TEXTBUTTON name="nextgen" id="b9b03db880bd4c49" memberName="nextgen" virtualName=""
              explicitFocusOrder="0" pos="225 300 150 24" bgColOff="ff7575e8"
              bgColOn="ff0606e6" buttonText="next generation &gt;&gt;" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="prevgen" id="9ba9053392282fa5" memberName="prevgen" virtualName=""
              explicitFocusOrder="0" pos="225 335 150 24" bgColOff="ff7575e8"
              bgColOn="ff0606e6" buttonText="&lt;&lt; prev generation" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="edit" id="904d34af933ba0e1" memberName="edit" virtualName=""
              explicitFocusOrder="0" pos="240 140 50 24" bgColOff="ff7575e8"
              bgColOn="ff0606e6" buttonText="edit" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="random" id="bb3211ca95fe4fb6" memberName="random" virtualName=""
              explicitFocusOrder="0" pos="300 140 70 24" bgColOff="ff7575e8"
              bgColOn="ff0606e6" buttonText="random" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: sine_png, 11683, "../../Builds/VisualStudio2010/sine.png"
static const unsigned char resource_GeneticProgrammingSynthesizerComponent_sine_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,2,88,0,0,0,50,8,6,0,0,0,128,150,165,201,0,0,0,44,116,69,88,116,
67,114,101,97,116,105,111,110,32,84,105,109,101,0,87,101,100,32,49,50,32,68,101,99,32,50,48,49,50,32,50,48,58,52,54,58,52,51,32,45,48,54,48,48,94,56,143,144,0,0,0,7,116,73,77,69,7,220,12,13,2,58,31,53,
151,68,202,0,0,0,9,112,72,89,115,0,0,11,18,0,0,11,18,1,210,221,126,252,0,0,0,4,103,65,77,65,0,0,177,143,11,252,97,5,0,0,44,250,73,68,65,84,120,218,237,93,7,156,21,213,245,62,179,13,65,64,236,6,29,99,44,
168,139,61,150,40,26,137,34,86,212,72,179,69,49,18,98,87,84,164,110,97,119,105,18,123,44,177,197,68,20,97,1,81,17,53,150,63,150,32,42,70,67,16,53,118,7,177,162,168,184,2,187,203,252,191,239,190,59,248,
120,251,202,204,123,83,158,102,190,223,111,246,206,155,157,185,115,207,189,119,238,57,247,222,83,68,98,196,136,17,35,70,140,24,49,98,248,10,35,234,2,196,136,17,35,70,58,152,151,154,165,210,67,106,197,
150,51,241,115,21,70,171,77,145,62,46,205,50,220,58,217,250,32,234,242,197,136,17,35,70,54,148,68,93,128,24,49,98,196,72,139,131,228,90,8,87,71,226,56,197,234,103,117,131,96,181,43,206,151,74,185,252,
203,156,110,110,18,117,241,98,196,136,17,35,27,242,92,193,178,141,154,26,25,141,147,17,134,33,27,174,187,106,203,99,56,102,226,218,61,99,199,26,77,81,19,231,5,53,53,118,25,202,94,85,82,34,35,240,179,34,
233,95,15,226,250,31,64,207,103,81,151,209,43,106,107,237,201,40,251,105,104,143,159,57,215,240,251,121,208,88,95,83,99,60,18,117,249,188,2,109,84,137,242,223,141,242,239,147,242,175,103,112,253,92,180,
209,146,168,203,232,21,117,117,246,238,173,173,50,13,109,180,171,115,13,180,172,70,114,239,202,149,114,225,85,87,25,223,69,93,198,40,96,206,50,43,101,173,44,144,86,233,110,13,180,172,245,254,55,211,188,
23,130,214,114,8,93,23,70,93,78,2,253,178,3,218,172,30,253,242,210,148,127,173,92,187,86,6,215,213,201,116,12,181,118,212,229,244,72,211,142,160,233,50,208,116,78,242,117,92,187,185,169,73,134,79,158,
108,124,27,117,25,189,33,230,89,63,6,252,212,120,150,103,1,75,55,234,253,32,248,56,252,108,193,249,95,145,62,135,10,233,139,180,55,142,13,112,92,137,235,53,104,224,85,81,19,232,146,166,163,144,140,7,13,
123,35,93,195,65,4,233,34,252,158,128,116,11,252,254,20,244,158,137,6,126,44,234,178,186,164,167,4,101,127,4,229,254,13,210,114,92,106,192,249,91,56,191,12,231,123,224,188,21,233,169,99,199,74,227,143,
101,224,31,61,218,54,203,202,228,49,10,34,40,255,71,184,116,6,210,77,241,187,30,199,206,248,253,20,126,15,71,159,91,24,117,89,221,2,131,201,112,126,39,40,127,123,164,239,241,18,142,29,113,12,193,181,45,
145,78,95,179,70,46,25,63,222,248,56,234,178,134,13,179,209,236,33,37,114,177,213,215,26,208,230,127,247,155,187,64,248,154,142,255,237,17,117,57,241,173,113,188,171,67,123,13,67,186,10,237,120,35,198,
138,153,16,154,199,35,61,24,215,202,32,100,157,135,255,223,134,190,217,18,117,121,93,210,180,25,146,55,140,196,150,108,19,202,95,139,243,157,112,28,13,250,126,198,239,15,215,142,105,104,48,94,139,186,
172,46,233,137,121,86,145,227,167,202,179,242,217,34,60,71,119,84,74,150,253,209,33,135,224,248,123,109,173,113,2,46,221,165,239,185,130,51,58,118,236,168,137,116,137,63,179,163,162,204,22,210,94,160,
231,18,28,119,226,119,15,252,111,14,153,29,6,148,27,185,218,16,117,65,221,0,229,190,6,73,111,148,123,53,202,125,6,218,166,138,109,180,122,181,244,198,239,106,92,255,22,199,52,204,232,250,71,93,86,55,64,
63,218,183,188,92,13,136,20,174,222,235,208,65,118,5,61,79,213,213,25,248,216,228,48,208,244,4,83,252,255,165,49,99,236,157,162,46,175,75,154,126,197,21,2,10,87,40,63,87,222,118,99,27,225,168,198,245,
209,236,139,184,54,0,116,79,192,189,219,70,93,222,72,96,75,81,175,40,12,25,98,151,107,1,127,24,25,0,5,17,180,223,229,96,106,207,163,111,254,6,183,220,206,251,48,94,222,132,255,255,49,234,242,186,193,208,
161,118,123,36,79,105,225,106,5,202,125,32,104,153,204,113,30,227,136,137,107,11,65,207,182,165,165,50,117,196,8,123,211,168,203,235,18,49,207,42,114,252,84,121,150,39,1,11,15,13,65,114,37,142,181,56,
254,140,10,152,157,82,73,231,227,24,137,211,38,116,232,203,81,49,135,71,77,104,54,112,128,4,77,207,224,116,123,28,43,113,12,198,224,248,172,243,127,208,247,118,75,139,250,240,94,64,227,238,128,89,233,
203,35,71,218,155,71,93,238,108,168,170,178,79,64,221,95,192,115,182,5,6,199,187,157,255,77,152,96,124,138,223,245,184,78,193,68,18,203,226,246,17,81,151,57,23,80,222,191,32,161,144,241,37,142,125,135,
15,255,97,123,2,109,180,12,131,253,40,156,46,229,111,156,223,134,54,221,34,234,50,231,160,136,43,199,119,161,254,217,151,150,32,253,101,242,246,4,218,232,14,38,160,251,99,252,239,76,164,191,99,95,141,
186,212,161,34,81,55,71,152,179,204,206,109,254,135,1,23,194,215,211,81,23,177,107,87,25,131,228,114,28,77,104,167,209,104,183,73,201,255,127,237,53,185,128,43,90,44,49,190,201,43,193,236,186,71,93,230,
92,232,220,89,198,129,22,50,229,119,193,220,186,161,95,46,74,254,255,146,37,210,3,227,250,92,222,83,81,33,117,195,134,217,157,162,46,115,54,196,60,43,230,89,81,192,225,89,174,5,44,234,25,128,184,201,122,
59,227,21,72,152,109,244,31,208,184,107,113,76,196,255,31,210,149,113,94,49,51,187,109,182,145,29,81,198,67,36,177,108,220,23,101,255,71,234,61,13,13,198,235,248,232,38,107,122,202,49,168,156,194,229,
204,168,203,158,14,40,215,241,232,168,119,131,22,50,240,71,113,220,146,225,86,238,217,207,197,193,165,243,1,23,94,104,183,139,186,236,89,104,234,7,154,118,147,196,246,203,80,180,209,151,109,239,49,94,
194,255,206,194,241,1,218,232,80,92,26,20,117,185,51,161,127,127,187,180,186,90,238,211,219,154,223,52,55,203,241,233,182,37,112,141,171,31,119,242,28,244,55,108,185,165,244,140,186,236,97,193,108,52,
185,109,115,11,122,177,5,182,248,132,218,46,228,245,7,204,142,230,12,243,79,56,61,5,71,164,250,118,122,92,27,204,115,61,30,78,74,189,167,177,209,104,69,59,146,113,188,138,163,3,152,221,35,122,133,168,
40,1,154,122,161,95,158,207,115,48,233,163,192,220,62,79,71,19,87,237,64,243,235,232,151,231,109,184,161,76,140,186,220,89,232,137,121,86,204,179,162,160,105,29,207,242,82,233,156,5,116,214,91,23,131,
114,220,123,47,103,223,120,201,241,104,224,223,69,77,112,58,112,121,27,3,222,147,60,71,25,95,73,215,81,29,180,111,47,243,64,207,84,125,239,117,72,122,70,93,254,84,144,113,163,108,195,113,116,194,241,14,
6,147,163,51,233,124,80,72,1,61,183,233,159,131,55,217,68,250,68,93,254,116,64,71,237,2,90,184,2,64,5,206,139,184,100,156,233,94,252,239,9,220,203,89,3,219,232,15,120,118,31,183,239,9,19,149,149,242,11,
124,23,74,175,8,131,224,57,227,198,25,239,100,186,23,76,238,47,100,12,60,167,62,197,143,104,75,38,111,64,128,26,38,37,50,27,195,237,96,249,167,244,64,250,24,142,169,184,254,95,105,145,255,226,22,174,174,
140,195,181,42,115,186,121,114,84,229,164,177,5,146,174,56,150,53,53,201,209,217,238,69,59,14,66,178,20,253,210,236,210,69,233,252,20,43,56,6,242,91,155,87,95,47,111,103,186,9,223,218,2,36,206,74,208,
57,163,71,219,63,143,186,224,25,16,243,44,137,121,86,152,72,229,89,174,4,44,60,68,105,204,177,38,25,15,98,23,103,187,31,255,127,16,201,77,250,231,233,120,62,114,101,212,84,64,170,231,135,68,133,205,175,
108,154,130,103,193,168,81,198,114,36,131,112,223,3,252,141,244,148,98,91,26,223,125,119,37,49,31,36,137,149,158,191,185,120,100,142,222,190,32,254,62,102,140,189,115,212,52,164,66,43,14,115,54,249,225,
170,85,50,43,215,253,84,100,165,197,137,36,20,197,143,139,186,252,169,168,174,182,233,207,105,190,46,235,179,117,117,114,95,182,251,33,124,89,24,240,39,176,143,162,46,78,43,47,87,237,251,147,4,132,165,
246,230,76,147,140,96,176,180,202,129,86,95,107,142,117,181,213,138,180,202,234,103,109,75,55,13,56,239,138,244,72,164,220,154,59,74,74,229,106,60,115,106,216,101,197,183,178,39,218,165,39,218,229,123,
234,86,229,178,168,107,104,48,254,131,251,20,99,68,122,31,158,47,186,173,66,140,209,115,117,249,62,194,113,180,97,228,84,36,230,24,255,9,142,146,178,50,181,45,95,84,110,51,98,158,21,243,172,40,144,202,
179,220,174,96,81,95,164,148,76,65,180,226,166,11,60,168,103,223,123,225,217,139,181,181,77,81,224,178,203,236,13,105,213,131,211,181,72,239,199,199,181,34,215,51,184,103,13,146,233,56,214,96,112,29,188,
193,6,242,235,168,233,112,192,229,95,204,108,104,25,195,85,145,37,40,107,131,11,122,90,112,239,52,50,9,46,161,151,150,202,100,228,179,85,212,180,56,24,53,202,166,153,238,96,77,211,77,19,39,170,1,35,23,
77,111,56,123,245,192,137,197,52,72,114,182,134,126,115,145,214,187,90,220,210,34,103,185,177,134,169,169,81,138,252,115,120,142,103,251,253,20,117,177,40,92,65,88,186,95,108,249,37,132,171,94,214,0,235,
223,185,158,129,144,181,8,247,210,71,214,100,179,209,60,45,172,178,114,139,15,223,202,197,146,152,161,190,138,62,55,199,229,163,87,160,31,63,135,116,3,60,255,219,176,202,235,6,13,13,246,214,220,118,194,
193,109,154,217,110,44,233,184,138,133,111,237,108,10,100,120,142,58,49,155,69,77,71,10,98,158,21,243,172,80,145,142,103,229,20,176,52,1,187,144,40,60,52,220,173,169,49,149,35,169,144,166,127,254,30,149,
185,171,155,231,194,64,199,142,242,16,63,62,156,126,82,91,107,156,237,246,57,208,116,47,146,41,60,71,227,134,62,115,206,130,74,109,174,43,205,205,114,140,219,135,234,235,141,103,209,166,180,202,88,134,
231,251,224,35,60,36,106,66,28,160,126,183,147,196,76,96,217,87,95,201,181,110,159,3,29,156,9,77,209,22,54,231,22,203,172,173,178,82,233,134,237,131,50,125,135,58,191,53,219,214,96,42,208,46,247,232,244,
140,173,182,146,200,182,197,130,128,57,195,220,85,74,228,125,8,74,95,200,80,57,36,213,231,85,54,64,16,251,15,158,235,13,177,224,74,8,89,161,108,235,128,73,117,68,223,58,139,231,72,95,112,251,28,125,18,
149,148,36,182,213,208,7,206,196,184,186,127,24,229,117,3,8,251,220,74,235,136,114,189,134,113,250,70,183,207,129,166,185,182,54,54,224,10,107,212,116,56,136,121,214,122,52,197,60,43,36,164,227,89,89,
5,44,206,186,145,12,160,99,54,28,159,131,184,231,189,188,16,29,252,97,238,107,235,151,23,133,117,6,125,83,32,57,88,151,111,170,215,231,209,184,11,245,179,123,211,212,62,106,122,8,180,205,67,250,244,137,
9,19,196,147,115,57,180,41,219,232,97,77,91,255,225,195,237,141,162,166,135,64,127,225,146,61,21,57,167,222,112,131,177,218,237,115,220,171,7,29,106,27,142,78,18,49,48,21,197,42,22,232,152,160,79,231,
215,213,25,55,120,121,246,163,143,228,41,208,164,62,88,180,245,41,81,211,226,23,32,20,245,67,66,23,27,215,74,7,57,203,178,44,207,254,109,172,254,214,107,24,197,142,128,144,53,17,194,218,25,65,151,153,
10,195,250,116,17,221,105,120,121,86,43,82,63,135,126,73,69,229,3,244,248,26,41,184,50,130,228,48,158,83,121,157,10,210,94,158,7,45,79,232,211,203,49,30,70,190,66,18,243,172,182,136,121,86,56,72,199,179,
178,10,88,59,236,32,93,180,130,220,218,164,173,23,215,224,150,13,18,199,202,228,162,98,208,61,64,37,156,68,203,10,253,17,61,227,245,121,60,251,184,54,129,221,21,199,133,35,70,216,27,71,73,15,62,152,237,
80,158,205,181,62,200,249,121,58,97,155,173,105,235,143,25,250,177,81,210,163,105,250,51,157,136,210,89,30,253,10,121,125,158,75,232,72,184,60,206,15,48,242,237,152,250,122,155,138,237,149,60,47,47,87,
113,245,60,225,214,91,141,102,244,219,233,154,182,30,168,159,193,81,211,84,8,204,105,230,222,230,76,179,30,163,207,109,56,70,88,253,172,9,214,49,86,115,190,249,89,39,89,180,40,236,5,33,107,60,132,172,
63,152,179,205,174,65,148,91,235,245,56,253,113,182,87,207,223,184,159,74,250,142,35,220,235,119,220,81,34,215,91,194,4,132,43,171,92,241,105,169,173,53,166,121,125,94,11,141,220,38,165,197,94,228,223,
90,204,179,218,34,230,89,161,208,148,150,103,101,21,176,80,240,106,125,186,40,31,70,167,241,40,152,220,139,180,160,41,43,115,191,20,24,20,80,142,161,58,157,170,21,27,61,129,126,70,146,164,239,83,65,83,
100,123,192,116,138,71,63,73,122,182,102,233,1,220,51,154,155,229,21,180,145,83,23,61,163,162,135,208,150,114,253,168,15,162,45,181,60,3,245,240,9,157,213,241,28,249,28,91,85,101,255,50,74,154,90,91,213,
128,205,45,152,127,163,174,191,202,39,143,213,171,229,67,36,84,212,165,95,168,95,23,155,82,113,38,64,144,58,29,199,28,90,1,234,163,78,202,132,43,120,99,164,85,126,15,225,40,175,54,78,5,132,180,215,49,
154,81,200,186,69,90,228,45,188,167,26,239,125,89,191,243,5,150,163,208,119,104,47,211,38,153,85,75,75,98,219,37,143,60,214,209,91,81,17,173,181,26,250,80,5,232,121,56,181,92,94,128,111,237,11,134,154,
225,57,190,185,61,144,231,54,81,210,20,243,172,182,136,121,86,176,200,198,179,50,10,88,163,70,217,91,211,242,128,231,32,100,122,190,47,215,21,232,248,172,217,11,21,220,49,170,138,0,163,237,129,74,216,
154,231,160,109,88,190,249,224,217,117,51,61,204,46,6,70,69,15,192,186,172,213,101,122,60,223,76,24,138,37,73,247,160,114,194,132,232,102,56,229,229,210,141,94,136,181,79,171,188,195,60,160,207,210,65,
34,205,201,119,41,41,137,206,164,151,91,48,160,229,8,28,92,161,153,152,111,40,14,180,17,149,137,235,120,78,51,114,208,183,103,84,52,185,133,217,104,94,46,182,92,143,227,30,89,33,187,73,169,28,9,1,136,
38,253,244,107,117,190,36,20,144,125,131,245,91,139,171,15,15,227,29,29,132,219,94,37,114,174,10,18,109,163,222,108,185,20,229,185,206,188,61,175,232,21,100,12,29,209,143,232,131,139,91,0,47,53,52,24,
111,229,89,204,101,206,246,6,67,207,112,156,245,179,14,60,66,185,50,225,183,214,190,125,130,137,231,137,167,112,60,129,250,97,52,133,51,163,50,196,136,121,86,102,196,60,43,56,100,227,89,25,7,27,52,194,
54,218,226,233,125,134,32,41,164,0,120,126,166,62,165,146,93,36,230,243,218,138,139,241,154,232,168,236,17,58,152,43,32,187,15,145,199,88,77,219,217,248,0,163,50,159,255,51,255,160,44,84,152,190,186,144,
140,90,91,133,150,91,180,80,233,177,106,149,68,22,68,215,81,232,214,179,155,121,249,230,163,117,73,238,211,245,19,153,48,210,161,131,98,58,27,227,104,6,61,247,21,146,215,226,197,63,184,170,64,61,29,93,
72,94,65,195,156,107,110,36,140,35,182,86,142,129,144,51,213,26,108,173,129,0,244,158,213,215,58,83,104,58,110,203,102,214,64,235,11,223,95,188,22,99,141,45,207,201,26,233,131,247,189,200,75,86,127,235,
97,41,151,99,48,218,157,33,93,36,223,80,74,199,75,194,114,240,203,186,58,35,239,239,67,175,174,114,11,235,125,28,189,42,42,34,181,236,218,139,127,208,55,95,31,49,194,248,186,0,154,62,4,77,206,214,85,195,
22,91,40,47,227,161,35,230,89,89,17,243,172,128,144,141,103,149,100,121,232,255,244,233,191,232,196,177,192,50,208,147,241,92,93,136,72,180,254,43,43,229,103,12,239,192,125,95,201,99,31,59,25,218,252,
245,25,29,116,152,75,226,149,97,211,195,89,21,232,57,144,231,116,210,134,50,189,91,72,126,16,72,222,164,213,157,206,111,44,102,78,135,70,64,19,45,127,84,88,7,110,199,20,154,31,242,248,39,83,244,101,186,
108,184,36,108,122,180,73,255,37,186,44,110,252,188,100,69,99,163,10,247,49,81,231,183,167,54,11,46,78,172,148,62,16,176,158,181,6,88,11,210,252,247,106,252,111,223,64,222,91,34,125,145,247,181,214,169,
214,122,190,169,172,19,172,79,32,120,221,139,26,220,207,107,150,90,103,69,249,84,210,174,22,10,66,125,189,241,184,227,64,86,199,142,11,29,252,214,240,157,223,172,203,240,207,66,243,67,94,235,86,35,49,
163,143,100,11,42,230,89,153,17,243,172,192,104,202,202,179,210,10,88,90,177,143,82,243,87,171,87,175,115,214,150,55,80,145,75,109,123,221,114,222,110,40,84,231,130,50,204,15,71,233,244,19,134,70,240,
129,166,167,146,246,181,143,42,40,179,60,128,129,158,78,214,156,153,226,163,62,101,251,170,115,2,218,246,10,155,38,96,15,12,146,92,66,230,246,94,33,179,53,7,180,244,26,167,207,67,167,103,227,141,213,64,
70,11,173,207,208,94,15,23,158,163,97,163,93,168,119,176,2,245,212,187,24,244,67,178,194,150,207,51,252,231,115,79,249,68,252,94,212,243,22,100,178,232,75,180,12,90,152,79,30,105,48,131,127,144,239,126,
24,15,67,103,118,12,156,203,148,2,35,102,255,158,172,90,51,224,95,56,102,233,60,7,134,237,67,42,230,89,174,104,138,121,150,255,200,202,179,210,10,88,24,80,118,163,213,2,78,255,155,46,30,85,62,104,109,
77,204,216,128,95,163,227,134,186,156,167,21,47,47,229,121,33,122,61,169,0,29,143,233,60,15,129,244,28,170,5,77,105,105,98,121,149,179,207,230,230,196,96,93,40,150,44,145,151,241,17,168,153,31,58,77,168,
157,149,142,231,146,6,253,69,5,46,135,43,112,214,6,58,156,173,130,208,63,62,71,15,4,109,68,115,113,31,4,44,229,120,148,102,231,142,203,134,35,11,204,46,56,36,234,253,88,243,110,179,109,120,31,91,232,158,
193,147,5,158,107,216,74,0,106,163,60,110,222,110,146,225,15,146,82,249,206,107,150,248,214,232,119,71,133,39,169,171,51,38,120,125,62,67,158,220,194,166,158,207,254,200,247,132,64,234,34,3,180,222,215,
118,60,199,247,177,120,210,164,252,183,7,29,224,91,251,6,253,125,150,174,167,115,145,111,193,43,208,94,16,243,44,119,136,121,150,127,112,195,179,218,8,88,220,118,112,36,119,219,71,37,84,234,196,36,76,
50,21,184,101,179,99,136,117,193,65,140,78,227,232,253,246,69,31,243,165,50,228,251,56,182,64,227,134,102,169,70,171,5,212,37,183,58,90,184,52,207,144,42,126,228,203,64,174,248,8,156,153,210,25,181,181,
182,103,151,2,5,192,209,9,248,144,138,178,126,101,138,142,239,244,97,90,56,185,118,88,90,40,232,187,6,109,68,255,53,190,108,15,38,3,3,191,242,243,197,128,209,160,105,219,176,104,242,132,21,66,37,240,183,
164,189,60,98,206,48,187,56,151,113,126,138,24,114,129,180,22,166,127,145,17,45,202,138,231,100,179,209,92,231,25,90,189,127,35,245,190,207,240,238,185,94,178,27,51,198,222,201,17,128,252,216,74,115,80,
93,109,188,66,189,26,158,163,143,134,170,135,85,94,174,116,18,59,107,154,124,27,227,235,234,84,60,191,219,52,77,161,109,125,198,60,203,19,98,158,229,31,114,242,172,54,2,22,10,187,135,246,24,75,175,182,
147,196,95,168,229,60,52,236,190,56,126,17,86,45,232,224,139,252,248,94,174,173,53,254,234,87,190,144,88,151,36,197,70,10,109,187,166,125,123,165,56,205,8,241,223,130,158,145,126,230,141,129,241,121,77,
83,9,210,13,195,160,135,202,156,250,227,35,124,89,189,74,194,10,14,146,52,161,229,118,76,93,93,56,241,171,208,191,105,89,194,65,229,45,28,11,10,207,113,189,188,185,250,193,129,151,223,234,31,195,160,199,
51,58,75,23,8,51,100,72,159,226,120,3,2,207,92,115,166,73,43,191,196,150,237,218,96,182,9,173,147,173,247,196,150,163,240,238,227,33,88,45,231,123,249,126,252,62,29,215,111,180,78,178,92,59,173,37,80,
191,92,105,91,164,125,246,228,12,225,227,17,206,138,207,33,96,222,67,130,168,143,84,224,61,29,156,160,232,192,125,77,77,235,182,140,124,128,218,194,118,234,136,19,154,14,97,208,20,243,44,247,136,121,150,
63,112,203,179,218,8,88,142,84,139,66,191,65,31,39,126,22,234,203,47,229,101,231,28,133,11,37,228,7,62,242,125,241,46,101,194,73,135,107,126,231,143,143,251,113,157,247,14,213,213,118,224,204,142,209,
186,209,54,170,131,22,98,230,154,9,116,158,8,90,150,107,154,66,49,231,173,172,20,58,226,116,150,143,95,46,52,191,20,122,214,162,190,184,93,69,37,207,131,90,91,101,247,48,104,2,61,116,118,170,44,180,24,
222,193,103,154,150,130,166,139,116,125,29,17,6,61,222,43,0,140,142,130,229,10,57,65,86,203,190,56,191,72,90,229,56,252,238,134,255,78,147,178,196,246,71,16,176,250,91,92,105,90,4,161,234,14,245,94,190,
127,173,156,165,188,189,223,103,254,220,75,94,104,59,42,5,83,177,125,86,93,157,225,139,207,46,7,45,45,98,177,191,211,39,16,126,134,229,215,140,99,62,183,159,62,196,251,27,114,5,170,246,10,231,251,101,
24,19,36,191,15,133,160,152,103,121,66,204,179,10,135,91,158,181,158,128,85,85,101,31,136,2,214,232,159,243,252,46,20,221,199,131,193,29,175,11,117,32,222,119,64,208,21,129,134,221,28,52,181,163,30,12,
222,189,200,239,252,145,231,7,218,228,180,51,222,115,40,59,83,144,244,224,125,91,235,56,123,223,33,245,20,6,194,45,146,156,40,238,8,122,194,48,81,118,44,252,158,249,248,227,117,74,233,190,1,76,146,2,150,
210,249,65,189,5,238,220,17,117,182,151,238,115,95,47,95,46,3,130,120,7,29,33,74,194,68,249,23,120,95,36,102,241,153,96,78,55,169,64,123,36,4,155,115,172,193,214,90,235,52,107,169,53,192,122,91,29,131,
173,22,8,58,108,227,223,153,141,102,32,214,89,42,120,180,33,71,67,168,186,70,189,51,241,254,153,184,118,55,157,156,106,125,44,47,120,46,201,88,194,55,232,109,146,59,121,78,43,168,48,194,152,56,253,159,
227,71,67,131,241,90,0,175,120,17,121,87,233,243,192,233,137,121,150,119,196,60,203,23,184,226,89,235,9,88,144,108,41,161,87,80,55,192,81,222,242,27,144,250,190,213,209,176,119,229,210,110,144,53,64,51,
121,188,231,38,253,115,54,24,237,35,126,191,67,71,53,191,130,231,58,78,220,97,65,210,132,58,83,78,51,185,93,129,119,7,162,83,132,119,112,54,64,43,15,134,28,9,84,63,68,123,246,237,171,127,46,98,88,152,
32,222,131,250,114,2,244,182,15,214,194,201,54,180,223,45,250,76,90,236,37,142,162,23,104,19,101,42,39,111,134,99,124,112,244,120,131,249,128,217,17,163,202,77,98,203,133,16,108,210,42,79,91,125,45,110,
27,142,131,192,83,229,49,123,119,40,81,12,241,37,171,191,245,241,122,215,19,239,219,69,54,18,79,46,59,106,107,141,183,234,234,188,197,232,243,128,217,58,101,127,9,116,60,28,57,210,38,227,118,86,60,103,
23,148,89,6,232,173,18,181,173,134,119,117,231,24,28,36,77,49,207,242,142,152,103,21,6,47,60,107,61,1,203,81,232,67,250,31,6,205,13,162,112,116,196,133,194,93,165,127,6,26,221,187,115,103,249,57,62,142,
237,180,239,143,155,10,206,48,3,154,155,149,84,238,88,69,5,166,116,172,245,135,156,144,31,247,6,245,30,29,48,217,113,138,25,116,4,118,126,220,202,111,14,61,100,7,248,30,229,115,133,12,6,239,185,56,168,
151,140,28,41,155,161,207,221,165,223,21,36,61,156,233,246,209,239,233,129,153,117,228,142,71,205,25,230,32,105,86,138,224,79,66,184,121,32,235,205,67,149,87,244,110,230,116,243,100,115,174,233,183,174,
78,63,177,215,57,138,92,7,173,127,245,59,8,90,151,152,141,102,239,60,86,178,130,0,67,205,168,89,61,117,4,131,124,17,152,80,87,29,47,240,19,189,109,30,20,28,165,236,189,48,6,251,190,242,151,140,152,103,
229,135,152,103,21,4,215,60,107,157,128,197,125,95,42,2,243,28,233,147,65,150,14,29,232,94,93,184,29,198,142,181,3,51,53,71,254,135,107,122,232,97,245,213,66,243,203,4,186,237,23,218,47,37,16,216,108,
160,181,85,54,229,172,16,167,43,156,61,231,160,192,184,87,146,216,130,218,8,125,163,224,56,110,233,192,153,0,18,165,220,139,143,131,75,188,5,121,58,207,134,37,75,228,53,244,135,225,154,182,192,24,89,69,
69,34,111,154,237,126,253,181,140,10,234,61,4,190,163,247,236,132,207,39,122,176,222,39,200,119,185,130,33,221,112,236,129,99,73,174,91,45,203,98,128,215,103,165,20,253,236,123,255,98,137,153,51,205,131,
241,254,195,100,85,122,51,112,171,159,245,2,254,127,39,70,190,199,100,163,96,5,26,55,208,174,68,148,135,109,110,223,85,87,219,129,233,144,64,192,58,69,191,231,229,250,122,227,254,224,104,146,207,157,21,
99,96,179,160,124,72,197,60,43,127,196,60,43,63,120,229,89,90,192,82,219,26,123,235,223,212,9,240,213,234,41,21,168,116,126,128,79,234,192,169,129,44,231,209,164,22,31,133,90,6,181,25,154,35,96,160,178,
85,165,211,34,8,131,100,32,122,62,142,245,15,222,245,143,66,195,174,228,2,7,126,212,27,7,97,122,223,237,163,59,150,223,216,64,47,181,242,227,123,68,123,27,14,4,52,231,69,189,41,101,68,208,181,59,3,221,
6,241,30,61,152,16,139,175,185,198,248,62,40,122,8,212,215,50,188,239,43,253,222,80,125,41,153,183,155,101,230,116,243,44,8,52,75,117,64,101,174,16,142,20,91,166,91,125,173,107,92,101,146,8,153,179,12,
199,93,120,254,51,157,207,151,56,110,68,254,249,182,15,191,249,77,164,125,22,79,241,84,190,167,211,80,67,30,215,239,124,31,116,44,66,26,137,95,177,230,102,21,198,132,202,238,237,48,102,5,178,5,165,245,
244,246,87,228,219,126,90,14,166,131,97,227,91,251,26,239,161,85,33,199,194,0,24,120,204,179,10,69,204,179,242,130,39,158,165,4,172,154,26,181,44,121,43,207,81,192,143,233,52,46,224,138,248,34,201,75,
110,32,146,38,64,19,241,109,117,72,138,64,244,13,146,161,183,131,56,115,239,130,115,223,253,139,160,179,116,5,45,187,234,159,243,130,166,135,208,49,211,136,1,140,95,229,119,254,73,10,183,159,163,79,4,
182,124,236,160,169,41,49,8,211,133,2,222,233,135,247,234,245,192,1,18,249,158,166,127,6,58,224,39,161,150,127,180,69,80,224,10,252,235,176,49,218,174,68,174,132,160,210,87,5,84,222,90,197,248,227,251,
15,130,176,210,223,85,30,165,242,180,62,163,64,214,77,229,83,166,242,217,30,249,79,49,159,55,75,115,101,97,222,103,110,136,247,93,102,54,154,243,41,44,161,60,135,81,112,131,144,151,217,90,201,80,202,215,
79,203,90,57,64,189,115,133,90,121,99,140,180,7,145,79,232,43,129,58,110,230,157,250,103,32,138,225,12,14,142,62,66,231,159,239,151,150,202,226,160,105,226,10,25,222,231,56,117,237,233,119,254,49,207,
42,28,49,207,242,14,175,60,171,68,23,234,151,250,161,23,68,164,96,151,252,110,224,40,36,226,157,229,104,8,223,99,87,57,202,156,72,223,68,69,188,17,52,61,140,171,4,90,254,146,252,110,159,65,63,34,244,189,
177,28,71,224,3,36,241,233,167,178,0,239,122,143,231,72,125,253,0,209,230,91,36,57,112,12,68,57,53,21,87,93,37,77,142,0,20,196,128,2,208,122,112,79,234,131,224,152,31,6,77,171,87,43,47,198,203,36,97,230,
31,158,195,74,91,26,32,160,28,171,182,220,0,235,64,171,21,66,205,20,8,42,116,191,48,194,188,221,44,201,153,71,194,116,251,65,228,49,1,199,10,149,207,137,214,114,140,74,3,145,127,79,249,56,59,61,74,161,
190,76,30,21,198,0,51,100,132,180,42,199,127,28,96,143,134,208,149,86,15,67,57,29,181,101,40,238,189,216,26,96,41,159,77,42,16,245,73,214,173,200,99,44,142,139,66,171,195,36,180,182,38,204,215,25,155,
176,182,214,190,204,207,188,25,75,17,194,200,29,250,231,131,53,53,134,111,14,83,179,1,124,229,86,125,186,155,142,231,232,103,222,49,207,42,16,49,207,242,134,124,120,86,9,151,90,241,241,237,169,31,122,
13,149,190,50,140,138,24,59,86,5,176,164,87,87,6,180,156,236,103,222,85,85,54,205,191,149,207,18,39,124,67,24,40,43,91,23,111,110,59,52,198,229,126,229,59,114,164,189,165,241,131,197,213,173,126,251,85,
202,4,109,29,161,150,64,41,56,48,52,128,143,217,179,179,30,137,246,89,138,25,117,40,194,8,183,46,68,59,141,100,16,85,58,139,243,249,5,83,116,93,209,247,149,175,254,188,50,129,97,65,108,10,12,137,247,250,
26,250,2,223,209,62,96,246,119,162,221,247,79,243,239,239,33,160,180,245,48,221,42,115,32,192,108,38,93,36,183,222,141,45,149,162,3,14,39,3,194,206,55,184,206,213,130,205,179,62,223,34,23,224,239,87,178,
66,78,132,128,246,140,53,208,250,2,233,104,97,72,28,8,128,74,0,107,251,78,6,132,157,135,123,219,50,176,86,229,113,63,146,248,142,248,6,104,113,249,12,183,9,145,250,186,138,86,94,46,12,236,236,8,56,255,
13,139,38,234,168,160,111,182,226,221,135,183,107,183,78,39,203,7,196,60,203,47,196,60,203,19,60,243,172,146,154,26,249,141,83,17,72,67,153,217,36,96,216,152,181,245,226,25,103,109,232,96,190,196,174,
210,38,148,61,113,202,229,201,199,113,254,66,88,20,181,180,200,199,218,219,51,173,162,14,246,43,95,124,4,219,33,161,131,70,14,142,211,195,162,71,195,209,159,32,147,245,109,166,136,122,82,161,5,208,62,
175,97,70,237,187,41,114,38,96,48,230,76,138,219,9,21,221,187,251,22,112,84,249,227,65,82,166,105,243,53,52,78,46,160,223,189,160,3,17,119,172,174,182,125,179,144,212,198,0,103,33,221,44,205,191,203,205,
185,102,121,155,171,37,74,64,104,135,33,174,213,229,107,54,119,121,95,58,252,17,111,185,92,249,214,74,2,132,44,42,187,126,132,26,241,230,121,155,94,160,13,239,177,10,253,0,250,37,3,130,255,93,21,195,246,
55,204,12,132,145,117,249,161,175,132,52,153,81,91,159,220,234,114,152,182,111,171,171,49,207,242,15,49,207,114,143,124,120,86,137,86,20,36,102,172,92,25,206,86,141,3,12,40,239,51,250,57,157,37,98,16,
216,187,240,28,213,150,73,39,228,85,167,43,226,101,12,92,31,134,69,15,61,202,34,25,163,223,237,155,194,44,232,81,121,113,233,51,72,203,146,116,88,178,68,62,77,10,116,234,75,48,77,12,40,221,64,211,65,154,
166,198,48,233,209,112,156,127,110,143,65,242,208,66,51,227,74,24,232,217,79,135,235,120,14,131,240,91,97,18,51,110,156,241,1,146,165,92,253,192,113,180,31,179,54,29,119,77,249,215,210,38,227,169,104,
47,77,114,108,155,171,134,50,145,94,96,157,106,229,246,16,110,200,211,16,106,206,77,189,108,78,53,119,16,110,229,218,57,173,17,215,66,144,203,100,153,148,62,20,79,171,218,82,221,203,156,102,238,210,230,
127,101,202,189,195,211,18,17,208,118,141,58,221,26,245,239,75,172,70,29,216,185,55,207,209,142,99,63,251,44,156,173,154,36,56,227,213,46,160,201,23,111,245,49,207,242,15,49,207,114,135,124,121,86,137,
83,0,74,177,87,93,101,132,58,123,35,99,112,172,160,132,190,107,124,64,69,133,28,229,156,131,209,249,18,177,219,11,240,177,208,191,8,245,73,42,208,40,87,22,154,31,189,130,11,183,60,18,8,157,30,90,223,33,
89,200,165,126,241,169,179,98,144,162,111,148,131,144,231,155,97,237,205,167,128,179,170,207,112,108,143,254,87,240,204,186,178,82,109,25,92,167,105,155,143,153,123,168,2,150,134,218,94,208,131,100,193,
102,241,104,151,62,24,80,200,16,23,98,150,251,78,155,27,18,186,86,55,154,51,204,19,169,215,100,206,50,59,155,51,205,161,66,47,222,218,237,64,78,116,80,117,182,135,217,136,39,167,153,221,180,101,226,254,
82,161,132,156,251,173,190,86,246,190,177,22,204,187,131,156,152,122,89,121,114,231,54,91,98,85,111,61,88,39,91,223,161,236,245,16,166,30,193,91,143,81,229,158,110,110,13,26,70,43,97,175,52,28,125,158,
116,160,162,54,250,15,235,149,43,161,251,251,17,92,184,172,76,126,173,125,191,81,8,159,31,148,35,223,44,112,156,142,238,140,50,212,251,148,103,204,179,124,68,204,179,114,35,95,158,85,130,206,226,88,61,
61,23,118,69,16,182,45,206,50,235,175,170,171,237,9,133,228,133,134,165,121,230,129,58,223,105,205,205,42,106,120,168,152,56,209,224,140,250,95,146,168,219,67,71,143,182,205,66,242,67,30,199,114,182,164,
157,17,62,19,54,61,4,6,254,5,40,3,7,102,250,180,41,104,185,151,62,113,74,75,19,22,50,244,93,83,95,111,132,182,28,158,68,207,39,58,84,132,100,138,130,238,5,73,121,44,168,171,147,17,97,211,163,241,62,142,
165,250,252,138,66,50,210,10,201,142,155,131,55,192,84,218,232,184,40,133,118,198,154,51,212,76,241,45,8,59,20,90,123,34,61,202,58,201,122,197,205,123,172,99,172,38,8,53,11,145,199,182,16,41,158,149,46,
200,163,68,254,38,140,195,102,187,10,218,123,51,238,171,85,190,175,52,148,112,85,34,179,144,231,27,214,64,43,173,190,17,202,126,147,174,163,135,85,185,75,212,247,186,19,134,227,35,172,223,90,129,43,23,
103,3,4,162,121,72,86,209,121,44,199,143,66,243,163,9,190,62,157,139,126,255,143,176,233,161,215,112,8,13,39,234,178,20,188,245,137,241,99,112,204,179,252,69,204,179,178,163,16,158,197,10,165,63,145,235,
190,249,38,188,125,223,20,44,195,251,47,99,57,168,148,86,72,70,148,50,145,199,133,72,57,64,61,169,59,78,232,192,140,255,28,73,40,218,237,143,134,57,39,223,124,24,54,65,135,93,113,60,21,135,166,160,154,
10,90,223,233,54,218,181,16,31,82,52,23,23,109,189,138,129,55,52,101,206,52,80,86,102,84,254,45,36,118,85,125,189,109,130,166,158,186,142,102,106,69,250,208,161,205,200,111,208,52,157,80,136,115,199,242,
114,57,168,164,36,81,63,12,65,146,233,62,171,159,245,24,132,149,195,145,110,142,99,43,156,159,224,88,230,185,129,217,104,246,82,97,109,90,228,88,60,187,37,242,216,30,7,205,186,111,134,128,52,60,215,243,
86,127,235,9,8,72,213,56,125,200,156,97,190,136,252,230,74,169,218,158,109,198,215,55,40,199,227,223,65,56,155,175,202,221,79,189,123,80,90,197,247,144,81,93,173,244,150,62,209,117,223,183,144,188,170,
170,236,99,117,40,20,126,119,161,233,57,166,2,125,137,179,126,42,136,87,214,214,230,239,72,21,140,159,58,117,13,49,207,242,31,49,207,202,140,66,120,150,163,171,113,95,208,78,17,51,1,13,208,130,15,144,
31,10,99,88,21,100,61,131,138,84,186,6,200,239,209,218,90,227,182,40,232,33,184,69,164,125,153,176,44,121,7,251,237,220,89,78,1,77,253,53,109,161,234,26,164,2,31,224,191,117,236,187,221,164,0,75,43,199,
227,56,58,237,171,212,103,136,138,158,37,75,196,2,61,255,39,9,247,6,121,91,207,160,94,168,139,209,139,91,48,160,199,213,202,77,128,184,93,167,149,56,26,242,201,64,199,66,83,250,32,160,137,22,70,79,5,86,
218,18,169,82,238,18,78,182,62,75,185,206,120,101,39,64,104,218,46,87,22,16,232,254,10,81,137,126,172,70,170,96,206,205,210,3,194,210,241,214,41,214,39,89,31,228,118,160,17,254,246,133,27,160,222,135,
233,211,237,193,24,242,118,60,106,24,202,105,105,23,244,203,25,232,167,97,249,101,107,3,237,114,96,14,202,67,163,136,65,249,230,83,81,33,221,144,199,150,250,103,204,179,124,68,204,179,50,163,16,158,69,
37,247,119,214,172,73,248,141,136,10,218,47,11,45,129,182,192,128,50,37,191,60,236,125,156,217,154,19,219,43,74,160,12,215,232,116,243,124,220,246,99,182,182,131,161,77,216,145,7,227,121,205,139,146,158,
113,227,12,110,169,61,161,203,83,147,79,30,220,155,167,121,51,149,68,241,243,79,58,207,72,160,61,187,15,167,245,29,151,197,199,140,177,119,205,39,31,237,169,154,120,174,190,222,8,52,92,71,46,232,88,108,
115,244,207,51,242,201,163,75,23,57,24,3,236,62,116,222,136,159,87,114,59,53,136,178,154,141,38,7,241,173,228,27,21,222,98,61,88,39,89,75,133,97,47,12,113,165,15,98,157,97,125,110,245,181,158,164,245,
32,132,181,15,114,190,123,150,73,203,197,3,49,95,127,48,8,218,124,192,115,232,155,239,82,111,9,231,23,228,147,193,168,81,246,207,74,18,65,175,85,8,17,186,243,136,146,32,204,252,157,112,64,71,84,87,219,
195,188,62,63,124,184,189,17,234,196,25,223,99,158,21,0,98,158,213,22,133,242,44,174,96,141,192,199,247,105,148,21,161,43,224,76,29,87,234,56,16,229,57,248,43,183,69,232,219,8,167,11,241,49,63,236,245,
121,191,129,178,204,164,181,1,227,34,25,198,58,139,6,215,40,43,83,180,56,203,154,175,234,40,245,81,227,28,77,219,206,104,35,207,186,70,244,211,164,103,177,79,212,213,25,247,120,125,222,111,64,32,122,9,
229,81,10,233,168,239,91,188,62,143,58,56,49,105,27,39,112,207,203,110,208,220,44,231,73,194,13,197,6,40,223,73,94,158,165,53,164,227,192,17,248,4,125,46,16,253,9,122,95,199,151,62,94,108,25,105,13,182,
154,210,222,180,86,9,87,251,65,24,242,197,20,126,61,216,202,16,96,129,117,138,21,153,128,159,13,20,106,209,47,71,50,212,12,126,30,79,61,29,47,207,211,236,191,188,92,5,65,166,87,248,149,24,15,95,139,154,
166,175,191,150,183,209,183,22,211,210,22,130,159,103,229,240,138,10,57,72,235,58,174,146,152,103,5,130,152,103,165,173,147,130,120,86,9,42,161,40,150,201,87,175,150,199,36,97,106,190,145,120,244,93,65,
19,74,36,74,143,6,29,228,238,134,6,35,242,1,133,203,200,24,80,110,211,101,242,20,84,150,30,99,229,135,112,12,11,49,91,139,204,116,60,5,100,220,47,162,141,218,139,199,112,17,160,233,32,39,204,0,234,101,
170,151,103,131,4,4,18,53,203,71,217,186,123,241,206,204,123,57,43,162,14,151,246,234,59,47,106,90,8,204,176,44,212,239,60,237,176,114,212,133,23,218,237,220,62,187,243,206,178,27,158,155,160,235,35,144,
54,82,171,71,229,42,6,218,7,86,63,43,163,62,131,213,223,250,24,226,197,149,16,180,38,153,141,102,111,223,222,63,205,236,38,52,225,54,100,110,16,244,249,5,140,31,211,209,22,173,122,75,236,118,143,143,255,
10,207,209,225,170,218,110,196,120,248,102,212,244,220,112,131,177,186,180,84,46,209,63,183,25,51,198,246,228,226,0,66,217,225,154,158,187,99,158,21,12,98,158,213,134,166,130,121,150,159,94,78,11,194,
196,137,198,87,32,70,13,238,168,140,129,92,29,112,89,9,29,240,28,103,107,220,39,165,21,85,209,12,156,24,20,168,227,179,76,151,115,142,135,71,25,98,160,175,14,49,48,54,234,229,125,7,58,152,230,56,237,9,
125,39,90,244,120,120,252,68,109,89,242,52,58,235,162,168,105,113,128,89,23,149,74,223,70,217,54,69,234,101,134,211,19,237,235,152,0,79,161,146,121,212,180,56,64,253,82,167,172,137,225,128,54,217,196,
125,184,8,48,64,101,157,133,54,122,204,113,59,225,59,90,133,142,80,233,227,41,55,147,180,229,115,161,179,83,35,191,237,206,244,68,162,62,12,217,95,121,145,47,114,160,29,148,159,49,206,162,169,27,231,230,
153,170,42,155,140,241,122,253,60,87,232,242,218,190,10,2,232,151,100,186,92,41,238,138,239,110,140,219,231,48,206,28,204,224,189,58,143,200,87,190,29,196,60,107,61,196,60,43,13,138,70,192,210,248,59,
136,121,157,123,192,32,236,42,84,198,6,185,30,0,225,251,161,83,168,248,97,244,179,130,10,125,59,106,34,28,112,70,128,50,157,173,151,145,127,237,198,175,205,144,33,54,151,35,213,18,58,29,15,34,15,47,157,
60,12,154,168,183,194,168,232,21,40,223,197,110,218,136,186,6,242,131,146,225,189,81,234,94,165,161,135,51,156,235,185,29,3,122,206,69,89,199,231,122,70,155,49,15,226,57,61,47,107,63,50,69,3,173,176,234,
132,234,153,229,102,101,14,247,244,118,220,77,112,171,32,87,148,120,183,48,103,154,125,205,25,230,155,56,222,197,57,5,38,174,94,81,87,44,183,242,252,215,74,71,138,51,234,222,120,126,57,142,183,245,113,
73,206,103,157,247,95,106,150,226,189,13,56,62,84,193,160,201,224,169,248,90,38,57,219,57,106,172,92,41,255,212,254,171,42,58,117,114,183,138,5,33,249,36,180,223,222,120,142,129,124,143,11,43,140,140,
27,232,241,240,58,28,223,225,56,193,173,208,40,9,31,111,92,241,185,190,169,73,22,70,77,71,10,98,158,21,243,172,140,40,42,1,139,131,1,14,206,44,57,40,108,159,43,160,34,189,20,163,163,142,76,186,84,52,179,
53,7,24,36,25,131,105,9,26,182,19,210,249,218,9,91,70,116,237,42,181,156,9,240,28,105,209,209,67,180,180,72,125,146,117,70,86,143,211,160,183,11,146,11,64,75,119,60,115,199,170,85,209,90,150,164,67,109,
173,113,131,182,40,228,7,120,154,30,48,50,2,76,172,23,29,122,226,25,11,253,111,82,84,166,213,57,208,155,138,234,220,98,114,20,105,115,128,202,212,92,230,159,187,102,141,63,51,106,8,52,12,218,60,89,214,
202,80,153,47,59,225,124,39,92,174,65,218,81,249,190,202,133,142,178,53,238,229,22,238,68,228,177,19,190,10,62,207,153,255,121,200,219,157,162,244,65,106,53,167,23,222,119,178,213,207,234,134,124,42,145,
231,253,210,34,15,154,83,76,95,3,16,251,13,58,209,52,180,187,10,244,179,163,240,45,101,93,201,171,171,179,89,63,14,83,184,51,140,128,193,94,193,50,129,38,174,144,150,118,238,44,207,231,18,178,170,171,
109,10,253,142,203,144,123,194,118,44,234,130,158,152,103,197,60,43,35,138,74,192,74,130,227,152,238,200,49,99,236,140,126,70,202,203,149,2,26,21,86,233,3,168,143,118,251,95,84,224,128,224,196,22,67,89,
105,189,84,151,233,94,238,99,147,14,158,99,150,115,197,71,31,201,139,46,95,19,42,32,205,211,130,231,10,77,83,255,108,142,233,40,176,224,56,75,211,116,199,164,73,198,215,81,151,63,67,57,25,188,149,219,
124,219,98,192,56,47,211,125,85,85,246,1,24,32,29,183,14,19,107,106,162,181,28,204,4,124,11,171,244,96,207,25,233,228,76,58,47,156,205,225,168,21,29,78,5,109,116,223,248,241,198,71,30,94,149,22,230,44,
179,29,132,26,234,165,12,178,6,88,115,173,171,173,86,8,56,43,112,208,57,232,197,56,114,111,199,150,202,24,220,119,23,158,185,26,121,124,105,25,150,77,223,91,210,170,244,113,46,55,167,153,155,101,45,195,
76,147,131,233,177,242,149,244,182,78,178,84,12,62,228,243,145,213,223,98,127,124,71,218,231,239,50,32,44,124,251,173,204,161,247,104,156,110,226,232,199,101,66,107,171,178,2,219,67,91,128,22,205,182,
83,42,154,155,149,183,122,110,97,239,9,33,171,42,211,125,232,151,39,227,91,187,73,7,170,38,227,142,34,234,131,91,196,60,43,230,89,109,80,172,2,22,125,182,80,130,110,87,90,42,15,163,17,187,166,222,64,93,
3,252,159,179,89,206,108,254,82,108,203,146,201,160,55,99,148,241,1,189,13,213,7,101,111,227,64,144,49,241,240,191,87,104,85,130,251,154,145,222,29,65,88,11,47,96,96,218,119,113,108,134,65,99,54,45,151,
210,208,116,180,109,39,6,80,58,172,92,177,66,121,11,46,74,160,141,30,69,157,115,43,130,150,47,13,24,36,119,74,189,135,86,118,165,165,74,119,164,82,111,193,132,238,25,219,11,234,234,140,161,72,62,227,106,
65,89,153,76,215,113,233,82,209,15,255,167,9,51,219,239,79,220,30,244,229,229,45,178,33,132,163,111,100,69,26,111,219,171,149,224,183,123,206,60,12,57,10,194,84,155,217,166,53,208,178,116,156,194,92,91,
76,7,227,190,39,173,193,214,55,105,254,71,65,207,151,80,39,65,66,175,216,144,121,211,122,110,139,234,106,123,90,170,211,68,198,158,196,65,38,168,2,17,131,41,244,15,51,158,157,87,48,220,12,245,116,244,
207,75,65,83,155,208,74,218,255,23,133,112,90,231,125,131,251,47,46,70,97,36,9,49,207,138,121,86,27,20,165,128,197,15,9,51,55,70,194,38,115,32,83,120,55,121,6,142,243,238,232,196,220,87,101,192,86,14,
180,158,77,236,35,160,233,196,164,96,174,183,160,33,251,56,255,67,67,111,11,122,232,24,146,31,37,117,95,118,12,202,255,144,143,244,172,210,209,197,201,188,184,95,253,161,14,177,226,208,116,30,102,159,
119,112,139,10,247,61,132,75,131,105,73,20,117,185,179,129,171,81,96,78,87,162,188,237,33,144,44,194,192,127,22,133,42,77,207,94,221,187,43,69,71,101,249,131,251,46,43,38,221,137,76,64,27,112,203,136,
186,71,59,130,166,133,201,109,164,7,77,122,66,231,96,114,115,109,173,49,172,200,153,216,255,36,184,173,70,207,225,56,93,69,39,144,248,166,110,24,54,204,238,228,252,31,191,255,134,163,138,204,29,253,178,
161,190,94,249,104,42,106,140,29,171,124,11,61,203,50,131,166,106,174,12,167,220,82,199,21,46,174,222,181,180,200,190,218,199,91,209,34,230,89,49,207,74,7,35,106,162,179,1,196,111,186,193,6,74,130,164,
190,6,43,231,70,164,219,224,56,14,149,176,33,210,101,223,125,39,187,76,158,108,124,27,117,89,221,96,210,36,187,19,202,59,87,199,228,226,74,9,37,234,165,58,182,22,247,239,151,99,128,28,24,181,195,74,47,
24,59,214,238,131,50,143,6,13,7,232,173,12,198,125,58,88,199,64,227,12,97,10,174,143,46,230,25,117,42,106,107,237,7,144,48,0,107,5,195,61,32,157,13,122,142,150,68,124,190,15,113,126,250,226,197,50,95,
7,21,45,122,208,233,36,102,108,111,82,167,2,244,124,206,217,51,46,239,129,193,132,219,130,27,112,166,214,218,42,23,251,25,164,90,109,17,218,242,6,142,51,173,126,214,122,254,180,204,70,243,28,140,60,231,
225,122,86,47,229,230,12,243,65,174,84,89,253,173,245,182,19,205,105,166,41,165,178,80,90,165,187,53,208,202,104,189,169,182,8,109,153,35,43,100,143,212,85,44,228,61,13,101,88,96,245,181,174,9,179,45,
10,1,4,254,11,185,77,200,177,15,109,198,109,220,59,105,41,138,243,195,181,112,69,93,152,9,126,25,40,4,13,50,183,118,237,228,98,174,160,210,225,47,251,37,206,185,29,67,255,93,61,113,190,28,253,114,0,198,
195,103,163,46,171,7,154,98,158,85,228,8,147,103,21,181,128,69,64,170,220,94,47,171,94,154,124,29,21,116,23,174,15,229,82,102,212,101,204,131,166,43,232,72,16,167,93,146,232,121,10,131,201,144,98,178,
176,115,15,219,168,169,81,126,119,70,232,65,132,43,34,84,208,61,187,182,150,157,55,154,248,124,133,0,66,214,153,180,240,1,13,235,246,234,185,138,208,212,36,183,253,88,6,199,100,96,6,189,51,102,156,119,
164,6,220,181,25,50,6,131,102,16,43,87,74,201,93,100,2,134,229,11,100,129,60,38,149,16,139,186,40,221,134,26,140,60,103,66,184,121,60,199,243,244,100,254,42,142,209,82,2,70,245,91,204,148,103,42,161,144,
49,23,111,131,128,54,217,69,25,238,194,187,118,129,48,214,151,250,87,230,3,102,71,105,150,58,181,253,248,189,244,176,78,183,190,10,177,25,10,6,198,14,42,84,79,161,165,160,115,77,135,52,154,241,229,151,
50,181,216,87,137,83,65,63,109,155,110,42,213,24,255,250,65,224,239,150,68,211,180,213,171,229,252,34,53,32,201,138,152,103,253,24,16,14,207,42,122,1,43,70,140,24,63,94,208,77,131,216,202,37,2,45,51,185,
221,186,2,191,135,89,253,45,87,250,107,122,21,234,175,56,165,195,77,174,204,80,233,182,6,194,213,181,174,158,191,215,236,36,237,148,37,222,185,200,135,204,186,19,210,127,67,96,27,2,1,239,71,179,170,26,
35,70,140,24,49,98,196,136,17,35,70,140,24,255,243,248,127,213,104,75,119,18,70,71,56,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* GeneticProgrammingSynthesizerComponent::sine_png = (const char*) resource_GeneticProgrammingSynthesizerComponent_sine_png;
const int GeneticProgrammingSynthesizerComponent::sine_pngSize = 11683;


//[EndFile] You can add extra defines here...
//[/EndFile]
