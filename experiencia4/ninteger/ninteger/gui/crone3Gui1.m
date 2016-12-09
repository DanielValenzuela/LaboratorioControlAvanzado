function varargout = crone3Gui1(varargin)
% CRONE3GUI1 M-file for crone3Gui1.fig
%      CRONE3GUI1, by itself, creates a new CRONE3GUI1 or raises the existing
%      singleton*.
%
%      H = CRONE3GUI1 returns the handle to a new CRONE3GUI1 or the handle to
%      the existing singleton*.
%
%      CRONE3GUI1('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in CRONE3GUI1.M with the given input arguments.
%
%      CRONE3GUI1('Property','Value',...) creates a new CRONE3GUI1 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before crone3Gui1_OpeningFunction gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to crone3Gui1_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help crone3Gui1

% Last Modified by GUIDE v2.5 17-Sep-2003 18:16:32

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @crone3Gui1_OpeningFcn, ...
                   'gui_OutputFcn',  @crone3Gui1_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin & isstr(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before crone3Gui1 is made visible.
function crone3Gui1_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to crone3Gui1 (see VARARGIN)

% Choose default command line output for crone3Gui1
handles.w = [];
handles.gainC = [];
handles.phaseC = [];
handles.G = [];
handles.vargain = [];
handles.varzeros = [];
handles.varpoles = [];
handles.strings = [];
% Update handles structure
guidata(hObject, handles);
% UIWAIT makes crone3Gui1 wait for user response (see UIRESUME)
uiwait(handles.crone3Gui1);


% --- Outputs from this function are returned to the command line.
function varargout = crone3Gui1_OutputFcn(hObject, eventdata, handles)
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
if ~isempty(handles)
    varargout{1} = handles.w;
    varargout{2} = handles.gainC;
    varargout{3} = handles.phaseC;
    varargout{4} = handles.strings;
    varargout{5} = handles.G;
    delete(handles.crone3Gui1);
else
    varargout{1} = [];
    varargout{2} = [];
    varargout{3} = [];
    varargout{4} = [];
    varargout{5} = [];
end


% --- Executes during object creation, after setting all properties.
function edit_wl_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_wl (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc
    set(hObject,'BackgroundColor','white');
else
    set(hObject,'BackgroundColor',get(0,'defaultUicontrolBackgroundColor'));
end



% --- Executes during object creation, after setting all properties.
function edit_wh_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_wh (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc
    set(hObject,'BackgroundColor','white');
else
    set(hObject,'BackgroundColor',get(0,'defaultUicontrolBackgroundColor'));
end



% --- Executes on button press in pushbutton_OK.
function pushbutton_OK_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton_OK (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if get(handles.radiobutton1, 'Value') == get(handles.radiobutton1, 'Max')
    handles.spec = str2double(get(handles.edit_spec1, 'String'));
    if isnan(handles.spec)
        errordlg('Provide a valid real number for the maximum closed-loop gain.', 'Error with the performance specification', 'modal')
        return
    end
else
    handles.spec = str2double(get(handles.edit_spec2, 'String'));
    if isnan(handles.spec) | handles.spec<=0
        errordlg('Provide a valid positive real number for the minimum closed-loop damping factor.', 'Error with the performance specification', 'modal')
        return
    end
end
wl = str2double(get(handles.edit_wl, 'String'));
if isnan(wl) | wl<=0
    errordlg('Provide a valid positive real number for the lower limit of the frequency interest range.', 'Error with wl', 'modal')
    return
end
wh = str2double(get(handles.edit_wh, 'String'));
if isnan(wh) | wh<=0
    errordlg('Provide a valid positive real number for the upper limit of the frequency interest range.', 'Error with wh', 'modal')
    return
end
if wh <= wl
    errordlg('The upper limit of the frequency interest range should be greater than the lower.', 'Error with wl and wh', 'modal')
    return
end
handles.strings.plant = get(handles.edit_plant, 'String');
try
    handles.G = evalin('base', handles.strings.plant);
    [z, p] = zpkdata(handles.G, 'v');
catch
    errordlg('Provide a valid LTI plant.', 'Error with the plant', 'modal')
    return
end
handles.strings.vargain = get(handles.edit_vargain, 'String');
try
    handles.vargain = evalin('base', handles.strings.vargain);
catch
    errordlg('The name you provided for the gain variations data variable does not seem to be valid.', 'Error with vargain', 'modal')
    return
end
if any(~isreal(handles.vargain)) | any(ischar(handles.vargain)) |...
        size(handles.vargain, 1) ~= 1 | size(handles.vargain, 2) ~= 2
    errordlg('The contents of the gain variations data variable are not valid.', 'Error with vargain', 'modal')
    return
end
handles.strings.varzeros = get(handles.edit_varzeros, 'String');
try
    handles.varzeros = evalin('base', handles.strings.varzeros);
catch
    errordlg('The name you provided for the zero variations data variable does not seem to be valid.', 'Error with varzeros', 'modal')
    return
end
if any(ischar(handles.varzeros)) | size(handles.varzeros, 1) ~= length(z) |...
        (size(handles.varzeros, 2) ~= 2 & length(z))
    errordlg('The contents of the zero variations data variable are not valid.', 'Error with varzeros', 'modal')
    return
end
handles.strings.varpoles = get(handles.edit_varpoles, 'String');
try
    handles.varpoles = evalin('base', handles.strings.varpoles);
catch
    errordlg('The name you provided for the pole variations data variable does not seem to be valid.', 'Error with varpoles', 'modal')
    return
end
if any(ischar(handles.varpoles)) | size(handles.varpoles, 1) ~= length(p) |...
        (size(handles.varpoles, 2) ~= 2 & length(p))
    errordlg('The contents of the zero variations data variable are not valid.', 'Error with varpoles', 'modal')
    return
end
guidata(hObject, handles);
if get(handles.radiobutton1, 'Value') == get(handles.radiobutton1, 'Max')
    [a, b, w0, handles.w, handles.gainC, handles.phaseC] =...
        crone3(handles.G, handles.vargain, handles.varzeros,...
        handles.varpoles, wl, wh, handles.spec);
else
    [a, b, w0, handles.w, handles.gainC, handles.phaseC] =...
        crone3(handles.G, handles.vargain, handles.varzeros,...
        handles.varpoles, wl, wh, handles.spec, 'd');
end
guidata(hObject, handles);
uiresume

% --- Executes on button press in pushbutton_Cancel.
function pushbutton_Cancel_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton_Cancel (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
uiresume % this handles the closing of the function


% --- Executes on button press in radiobutton1.
function radiobutton1_Callback(hObject, eventdata, handles)
% hObject    handle to radiobutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton1
button_state = get(hObject, 'Value');
if button_state == get(hObject, 'Max')
    set(handles.radiobutton2, 'Value', 0);
elseif button_state == get(hObject,'Min')
    set(handles.radiobutton2, 'Value', 1);
end


% --- Executes on button press in radiobutton2.
function radiobutton2_Callback(hObject, eventdata, handles)
% hObject    handle to radiobutton2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton2
button_state = get(hObject, 'Value');
if button_state == get(hObject, 'Max')
    set(handles.radiobutton1, 'Value', 0);
elseif button_state == get(hObject,'Min')
    set(handles.radiobutton1, 'Value', 1);
end


% --- Executes during object creation, after setting all properties.
function edit_plant_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_plant (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc
    set(hObject,'BackgroundColor','white');
else
    set(hObject,'BackgroundColor',get(0,'defaultUicontrolBackgroundColor'));
end



% --- Executes during object creation, after setting all properties.
function edit_spec1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_spec1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc
    set(hObject,'BackgroundColor','white');
else
    set(hObject,'BackgroundColor',get(0,'defaultUicontrolBackgroundColor'));
end



% --- Executes during object creation, after setting all properties.
function edit_spec2_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_spec2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc
    set(hObject,'BackgroundColor','white');
else
    set(hObject,'BackgroundColor',get(0,'defaultUicontrolBackgroundColor'));
end



% --- Executes during object creation, after setting all properties.
function edit_vargain_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_vargain (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc
    set(hObject,'BackgroundColor','white');
else
    set(hObject,'BackgroundColor',get(0,'defaultUicontrolBackgroundColor'));
end



% --- Executes during object creation, after setting all properties.
function edit_varzeros_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_varzeros (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc
    set(hObject,'BackgroundColor','white');
else
    set(hObject,'BackgroundColor',get(0,'defaultUicontrolBackgroundColor'));
end



% --- Executes during object creation, after setting all properties.
function edit_varpoles_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_varpoles (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc
    set(hObject,'BackgroundColor','white');
else
    set(hObject,'BackgroundColor',get(0,'defaultUicontrolBackgroundColor'));
end