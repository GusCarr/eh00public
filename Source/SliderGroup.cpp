// SliderGroup.cpp

#include "SliderGroup.h"

//==============================================================================
SliderGroup::SliderGroup()
{
    const int widthI = (int) (width0 / howMany);

    for (unsigned int I = 0; I < howMany; I++)
    {       
        sliders.add(new juce::Slider(juce::String(I)));

        sliders[I]->setRange(0.0, 1.0);
        sliders[I]->setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
        sliders[I]->setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
        
        addAndMakeVisible(sliders[I]);
        
        myLookAndFeel.setForegroundColour(juce::Colours::black);
        myLookAndFeel.setBackgroundColour(juce::Colours::orange);        
        myLookAndFeel.setFillBack(true); 
        myLookAndFeel.setBackgroundAlpha(0.6); 
        myLookAndFeel.setWithBar(false);
        

        sliders[I]->setLookAndFeel(&myLookAndFeel);
        sliders[I]->setBounds(x0 + widthI * I, y0, widthI, height0);

        sliders[I]->addListener(this);
    }
}

void SliderGroup::setName(const juce::String nameIn)
{
    name = nameIn;
}

void SliderGroup::paint(juce::Graphics &g)
{
    // pass.
}

float SliderGroup::getSliderValue(const int Index)
{
    return sliders[Index]->getValue();
}

void SliderGroup::resized()
{    
    width0 = getWidth();
    height0 = getHeight();    

    const int widthI = (int) (width0 / howMany);

    for (unsigned int I = 0; I < howMany; I++)
    {
        sliders[I]->setBounds(x0 + widthI * I, y0, widthI, height0);
    }  
}

void SliderGroup::sliderValueChanged(juce::Slider* theSlider)
{
    DBG(" Group: " + name + ",  slider:" + juce::String(theSlider->getName()) + ", value =" + juce::String(theSlider->getValue()));
}

// ====
SliderGroup::~SliderGroup() // Destructor.
{
    for (unsigned int I = 0; I < howMany; I++)
    {
        sliders[I]->removeListener(this);
    }
}

// eof.-