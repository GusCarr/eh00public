// SliderGroup.cpp

#include "SliderGroup.h"

//==============================================================================
SliderGroup::SliderGroup()
{
    //
}

void SliderGroup::realise(const int inHowMany)
// void SliderGroup::init(const int inHowMany, int ix, int iy, int iW, int iH)
{
//     x0 = ix;
//     y0 = iy;
//     width0 = iW;
//     height0 = iH;
    if (inHowMany < 1)
    { 
        howMany = 1;
    }
    else
    {
        howMany = inHowMany;    // sets the amount of sliders.
    }
    
    const float widthI = (float) width0 / (float) howMany;

    for (unsigned int I = 0; I < howMany; I++)
    {       
        sliders.add(new juce::Slider(juce::String(I)));

        sliders[I]->setRange(0.0, 1.0);
        sliders[I]->setTextBoxStyle(juce::Slider::NoTextBox, true, 1, 1);        
        sliders[I]->setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
        
        addAndMakeVisible(sliders[I]);
        
        myLookAndFeel.setForegroundColour(foregroundColour);
        myLookAndFeel.setBackgroundColour(backgroundColour);        
        myLookAndFeel.setFrameColour(frameColour);       
        myLookAndFeel.setWithFrame(withFrame);
        myLookAndFeel.setFillBack(true); 
        myLookAndFeel.setBackgroundAlpha(backgroundAlpha); 
        myLookAndFeel.setWithBar(false);        

        sliders[I]->setLookAndFeel(&myLookAndFeel);
        // sliders[I]->setBounds(x0 + widthI * I, y0, widthI, height0);
        sliders[I]->setBounds((widthI * (float) I), - 0.5 * widthI, widthI, height0 + widthI);

        sliders[I]->addListener(this);
    }    
}

void SliderGroup::setName(const juce::String nameIn)
{
    name = nameIn;
}

void SliderGroup::setForegroundColour(const juce::Colour inForegroundColour)
{
    foregroundColour = inForegroundColour;
}

void SliderGroup::setBackgroundColour(const juce::Colour inBackgroundColour)
{
    backgroundColour = inBackgroundColour;
}

void SliderGroup::setFrameColour(const juce::Colour inColour) 
{
    frameColour = inColour;
};

void SliderGroup::setBackgroundAlpha(const float inAlpha)
{
    backgroundAlpha = inAlpha;
}

void SliderGroup::setWithFrame(const bool choice)
{
    withFrame = choice;
}

void SliderGroup::paint(juce::Graphics &g)
{
    // pass.
}

void SliderGroup::setSliderValue(const int Index, const double value)
{
    sliders[Index]->setValue(value);
}

float SliderGroup::getSliderValue(const int Index)
{
    return sliders[Index]->getValue();
}

void SliderGroup::resetValues(const double value)
{
    for (int I = 0; I < howMany; I++)
    {
        setSliderValue(I, value);
    }
}

void SliderGroup::resized()
{    
    if (howMany > 0)
    {
        width0 = getWidth();
        height0 = getHeight();    
        
        const float widthI = (float) width0 / (float) howMany;
    
        for (unsigned int I = 0; I < howMany; I++)
        {            
            sliders[I]->setBounds((widthI * (float) I), - 0.5 * widthI, widthI, height0 + widthI);           
        }  
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