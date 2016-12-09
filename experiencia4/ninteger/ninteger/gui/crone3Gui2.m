function varargout = crone3Gui2(varargin)
% CRONE3GUI2 M-file for crone3Gui2.fig
%      CRONE3GUI2, by itself, creates a new CRONE3GUI2 or raises the existing
%      singleton*.
%
%      H = CRONE3GUI2 returns the handle to a new CRONE3GUI2 or the handle to
%      the existing singleton*.
%
%      CRONE3GUI2('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in CRONE3GUI2.M with the given input arguments.
%
%      CRONE3GUI2('Property','Value',...) creates a new CRONE3GUI2 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before crone3Gui2_OpeningFunction gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to crone3Gui2_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help crone3Gui2

% Last Modified by GUIDE v2.5 19-Sep-2003 12:28:51

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @crone3Gui2_OpeningFcn, ...
                   'gui_OutputFcn',  @crone3Gui2_OutputFcn, ...
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


% --- Executes just before crone3Gui2 is made visible.
function crone3Gui2_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to crone3Gui2 (see VARARGIN)

% Choose default command line output for crone3Gui2
handles.output = tf(0);
% handling inputs
handles.w = varargin{1};
handles.gainC = varargin{2};
handles.phaseC = varargin{3};
handles.Ts = varargin{4};
% getting the dialogue ready
handles.indexes = [];
set(handles.listbox1, 'String', num2str(handles.w))
redraw(handles)
% Update handles structure
guidata(hObject, handles);
% UIWAIT makes crone3Gui2 wait for user response (see UIRESUME)
uiwait(handles.crone3Gui2);


% --- Outputs from this function are returned to the command line.
function varargout = crone3Gui2_OutputFcn(hObject, eventdata, handles)
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
if ~isempty(handles)
    varargout{1} = handles.output;
    delete(handles.crone3Gui2);
else
    varargout{1} = tf(0);
end


% --- Executes during object creation, after setting all properties.
function popupmenu1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to popupmenu1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc
    set(hObject,'BackgroundColor','white');
else
    set(hObject,'BackgroundColor',get(0,'defaultUicontrolBackgroundColor'));
end


% --- Executes on selection change in popupmenu1.
function popupmenu1_Callback(hObject, eventdata, handles)
% hObject    handle to popupmenu1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
redraw(handles)
% Hints: contents = get(hObject,'String') returns popupmenu1 contents as cell array
%        contents{get(hObject,'Value')} returns selected item from popupmenu1


% --- Executes during object creation, after setting all properties.
function listbox1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to listbox1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: listbox controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc
    set(hObject,'BackgroundColor','white');
else
    set(hObject,'BackgroundColor',get(0,'defaultUicontrolBackgroundColor'));
end


% --- Executes on button press in pushbutton_delete.
function pushbutton_delete_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton_delete (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
index_selected = get(handles.listbox2, 'Value');
handles.indexes = handles.indexes(setdiff(1:end, index_selected));
set(handles.listbox2, 'Value', []); % nothing may be selected in the end
set(handles.listbox2, 'String', num2str(handles.w(handles.indexes)));
redraw(handles)
% Update handles structure
guidata(hObject, handles);


% --- Executes on button press in pushbutton_add.
function pushbutton_add_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton_add (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
index_selected = get(handles.listbox1, 'Value');
handles.indexes = union(handles.indexes, index_selected);
set(handles.listbox2, 'String', num2str(handles.w(handles.indexes)));
redraw(handles)
% Update handles structure
guidata(hObject, handles);


% --- Executes during object creation, after setting all properties.
function listbox2_CreateFcn(hObject, eventdata, handles)
% hObject    handle to listbox2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: listbox controls usually have a white background on Windows.
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
if isempty(handles.indexes)
    errordlg('Please select some frequencies first.', 'Error with frequencies', 'modal')
    return
end
n = str2double(get(handles.edit_n, 'String'));
if isnan(n) | ~isinteger(n) | n<=0
    errordlg('Specify the number of zeros and poles with a valid positive integer number.', 'Error with n', 'modal')
    return
end
if handles.Ts
    handles.output = crone2z(handles.w(handles.indexes),...
        handles.gainC(handles.indexes), handles.phaseC(handles.indexes),...
        n, handles.Ts);
else
    handles.output = crone2(handles.w(handles.indexes),...
        handles.gainC(handles.indexes), handles.phaseC(handles.indexes), n);
end
% Update handles structure
guidata(hObject, handles);
uiresume

% --- Executes on button press in pushbutton_Cancel.
function pushbutton_Cancel_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton_Cancel (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
uiresume % this handles the closing of the function

% --- Redraws the plots
function redraw(handles)
% handles     needed for handling everything
plot_type = get(handles.popupmenu1, 'Value');
switch plot_type
    case 1 % Bode diagram
        axes(handles.plot)
        plot(0) % this is for clearing whatever might appear behind in axes plot
        set(handles.plot, 'Visible', 'off')
        set(handles.plot1, 'Visible', 'on')
        set(handles.plot2, 'Visible', 'on')
        axes(handles.plot1)
        semilogx(handles.w, handles.gainC, 'b.',...
            handles.w(handles.indexes), handles.gainC(handles.indexes), 'r.')
        grid
        xlabel('Frequency (rad/s)')
        ylabel('Gain (dB)')
        axes(handles.plot2)
        semilogx(handles.w, handles.phaseC, 'b.',...
            handles.w(handles.indexes), handles.phaseC(handles.indexes), 'r.')
        grid
        ylabel('Phase (degrees)')
    case 2 % Nichols plot
        axes(handles.plot1)
        plot(0) % this is for clearing whatever might appear behind in axes plot1
        axes(handles.plot2)
        plot(0) % this is for clearing whatever might appear behind in axes plot2
        set(handles.plot, 'Visible', 'on')
        set(handles.plot1, 'Visible', 'off')
        set(handles.plot2, 'Visible', 'off')
        axes(handles.plot)
        plot(handles.phaseC, handles.gainC, 'b.',...
            handles.phaseC(handles.indexes), handles.gainC(handles.indexes), 'r.')
        ngrid
        xlabel('Phase (degrees)')
        ylabel('Gain (dB)')
    case 3 % Nyquist plot
        axes(handles.plot1)
        plot(0) % this is for clearing whatever might appear behind in axes plot1
        axes(handles.plot2)
        plot(0) % this is for clearing whatever might appear behind in axes plot2
        set(handles.plot, 'Visible', 'on')
        set(handles.plot1, 'Visible', 'off')
        set(handles.plot2, 'Visible', 'off')
        response = 10.^(handles.gainC/20) .* exp(j * handles.phaseC);
        axes(handles.plot)
        plot(real(response), imag(response), 'b.',...
            real(response(handles.indexes)), imag(response(handles.indexes)),...
            'r.', -1, 0, 'mx')
        grid
        xlabel('Real')
        ylabel('Imaginary')
end


% --- Executes during object creation, after setting all properties.
function edit_n_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_n (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc
    set(hObject,'BackgroundColor','white');
else
    set(hObject,'BackgroundColor',get(0,'defaultUicontrolBackgroundColor'));
end