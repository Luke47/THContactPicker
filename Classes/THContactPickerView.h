//
//  ContactPickerTextView.h
//  ContactPicker
//
//  Created by Tristan Himmelman on 11/2/12.
//  Copyright (c) 2012 Tristan Himmelman. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "THContactView.h"

@class THContactPickerView;

@protocol THContactPickerDelegate <NSObject>

- (void)contactPickerTextViewDidChange:(NSString *)textViewText;
- (void)contactPickerDidRemoveContactView:(UIView *)contact;
- (void)contactPickerDidResize:(THContactPickerView *)contactPickerView;
- (BOOL)contactPickerTextFieldShouldReturn:(UITextField *)textField;

@end

@interface THContactPickerView : UIView <UITextViewDelegate, THContactViewDelegate, UIScrollViewDelegate, UITextInputTraits>

@property (nonatomic, strong) UIScrollView *scrollView;
@property (nonatomic, strong) THContactTextField *textField;
@property (nonatomic, strong) THContactView *selectedContactView;
@property (nonatomic, assign) IBOutlet id <THContactPickerDelegate>delegate;

@property (nonatomic, assign) BOOL limitToOne;				// only allow the ContactPicker to add one contact
@property (nonatomic, assign) CGFloat verticalPadding;		// amount of padding above and below each contact view
@property (nonatomic, assign) NSInteger maxNumberOfLines;	// maximum number of lines the view will display before scrolling
@property (nonatomic, strong) UIFont *font;

- (UIView *)addContact:(id)contact withName:(NSString *)name;
- (void)removeContact:(id)contact;
- (void)removeContactView:(THContactView *)contactView;
- (void)removeAllContacts;
- (BOOL)resignFirstResponder;

// View Customization
- (void)setContactViewStyle:(THContactViewStyle *)color selectedStyle:(THContactViewStyle *)selectedColor;
- (void)setPlaceholderLabelText:(NSString *)text;
- (void)setPlaceholderLabelTextColor:(UIColor *)color;
- (void)setPromptLabelText:(NSString *)text;
- (void)setPromptLabelAttributedText:(NSAttributedString *)attributedText;
- (void)setPromptLabelTextColor:(UIColor *)color;
- (void)setFont:(UIFont *)font;

@end
